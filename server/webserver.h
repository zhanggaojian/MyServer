#ifndef WEBSERVER_H
#define WEBSERVER_H
#include<iostream>
#include<unistd.h>
#include<string.h>
#include<sys/epoll.h>
using namespace std;

class WebServer{
public:
    WebServer();
    ~WebServer();
    //服务器初始化
    void init(int port,string user,string pwd,string databasename,
    int opt_linger,int trigMode,int sql_num,int thread_num,int actor_model);

    //数据库连接池
    void sql_pool();

    //线程池

    //初始化服务端的事件模式
    void InitEventMode(int trigMode);

    //事件监听

    //服务器运行

public:
    //重新定义一遍，方便后面使用变量
    int m_port;
    string m_user;
    string m_pwd;
    string m_databasename;
    int m_trigMode;
    int m_opt_linger;
    int m_sql_num;
    int m_thread_num;
    int m_actor_model;

    char* srcDir;//用于存储当前项目的绝对路径

    uint32_t m_listenEvent;
    uint32_t m_connEvent;
};
#endif