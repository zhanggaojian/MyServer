#include "sqlconnpool.h"

SqlConnPool::SqlConnPool(){
    m_curConn=0;
    m_FreeConn=0;
}

SqlConnPool::~SqlConnPool(){

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
}

MYSQL* SqlConnPool::GetConn(){
    MYSQL* rescon=nullptr;

    if(connList.size()==0) return nullptr;

    rescon = connList.front();
    connList.pop_front();

    --m_FreeConn;
    ++m_curConn;

    return rescon;
}

