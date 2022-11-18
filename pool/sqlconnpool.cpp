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

    
}

