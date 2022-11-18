#include "webserver.h"

WebServer::WebServer(){
    srcDir = getcwd(nullptr,256);
    // assert(srcDir);//检查参数合法性，如果值为假，则打印错误信息。已放弃使用assert()的原因是，频繁的调用会极大的影响程序的性能，增加额外的开销。
    strcat(srcDir,"/resource/");
}

WebServer::~WebServer(){}

void WebServer::init(int port,string user,string pwd,string databasename,
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
}

void WebServer::sql_pool(){
    
}

void WebServer::InitEventMode(int trigMode){//触发模式
    m_listenEvent=EPOLLRDHUP;//监听文件描述符，看是否有连接请求事件
    m_connEvent=EPOLLONESHOT | EPOLLRDHUP;//这个代表的是已经连接的文件描述符，用于和客户端通信的文件描述符，看是否有读写事件
    switch(trigMode){
        case 0:  //使用默认值
            break;
        case 1:
            m_connEvent |= EPOLLET;
            break;
        case 2:
            m_listenEvent |= EPOLLET;
            break;
        case 3:
            m_listenEvent |= EPOLLET;
            m_connEvent |= EPOLLET;
            break;
        default:
            m_listenEvent |= EPOLLET;
            m_connEvent |= EPOLLET;
            break;
    }
}

// int main(){
//     WebServer s(0,"1","2","3",4,5,6,7,8);
//     std::cout<<s.srcDir<<std::endl;
//     return 0;
// }