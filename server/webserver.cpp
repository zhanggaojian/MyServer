#include "webserver.h"

WebServer::WebServer(int port,string user,string pwd,string databasename,
    int opt_linger,int trigMode,int sql_num,int thread_num,int actor_model){
    //初始化各种参数
    m_port=port;
    m_user=user;
    m_pwd=pwd;
    m_databasename=databasename;
    m_opt_linger=opt_linger;
    m_trigMode = trigMode;
    m_sql_num=sql_num;
    m_thread_num=thread_num;
    m_actor_model=actor_model;

    srcDir = getcwd(nullptr,256);
}

WebServer::~WebServer(){}

// int main(){
//     WebServer s(0,"1","2","3",4,5,6,7,8);
//     std::cout<<s.srcDir<<std::endl;
//     return 0;
// }