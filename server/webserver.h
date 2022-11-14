#ifndef WEBSERVER_H
#define WEBSERVER_H
#include<iostream>
#include<unistd.h>
using namespace std;

class WebServer{
public:
    WebServer(int port,string user,string pwd,string databasename,int trigMode,int opt_linger,int sql_num,int thread_num,int actor_model);
    ~WebServer();
    //处理事件
    void eventLoop();

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
};
#endif