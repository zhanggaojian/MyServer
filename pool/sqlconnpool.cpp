#include "sqlconnpool.h"

SqlConnPool::SqlConnPool(){
    m_curConn=0;
    m_FreeConn=0;
}

SqlConnPool::~SqlConnPool(){
    ClosePool();
}

SqlConnPool* SqlConnPool::GetInstance(){
    static SqlConnPool sconpool;
    return &sconpool;
}

void SqlConnPool::SqlInit(string host,int port,string user,string pwd,string dbname,int connSize){
    m_host=host;
    m_port=port;
    m_user=user;
    m_passwd=pwd;
    m_databasename=dbname;
    m_maxConn=connSize;

    //创建数据库连接
    for(int i=0;i<m_maxConn;i++){
        MYSQL* con=nullptr;

        con=mysql_init(con);

        if(con==nullptr){
            std::cout<<"MYSQL Error"<<endl;
            exit(1);//退出进程，只要不是0，都是异常退出，是0就是正常退出。
        }

        con=mysql_real_connect(con,m_host.c_str(),m_user.c_str(),m_passwd.c_str(),m_databasename.c_str(),port,nullptr,0);

        if(con==nullptr){
            std::cout<<"MYSQL Error"<<std::endl;
            exit(1);
        }

        connList.push_back(con);
        ++m_FreeConn;
    }
    m_maxConn = m_FreeConn;
    sem_init(&m_sem,0,m_maxConn);
}

MYSQL* SqlConnPool::GetConn(){
    MYSQL* rescon=nullptr;

    if(connList.size()==0) return nullptr;

    sem_wait(&m_sem);//首先需要连接池中有连接

    //其次需要取连接的时候，其他线程没操作
    {
        unique_lock<mutex> lock(m_mtx);

        rescon = connList.front();
        connList.pop_front();

        --m_FreeConn;
        ++m_curConn;
    }

    return rescon;
}

void SqlConnPool::FreeConn(MYSQL* conn){
    if(conn==nullptr) return;
    unique_lock<mutex> lock(m_mtx);

    connList.push_back(conn);
    ++m_FreeConn;
    --m_curConn;

    sem_post(&m_sem);
}

int SqlConnPool::GetFreeConnNum(){
    unique_lock<mutex> lock(m_mtx);
    return connList.size();
}

void SqlConnPool::ClosePool(){
    unique_lock<mutex> lock(m_mtx);
    if(connList.size()>0){
        for(auto x:connList){
            mysql_close(x);
        }
        m_curConn=0;
        m_FreeConn=0;
        connList.clear();
    }
}

