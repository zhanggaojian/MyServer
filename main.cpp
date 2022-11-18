#include<iostream>
#include "config.h"
#include "webserver.h"
using namespace std;

int main(int argc,char* argv[]){
    //命令行参数解析
    Config config;
    config.parse_arg(argc,argv);

    WebServer server;
    
    //初始化
    server.init();

    //数据库
    server.sql_pool();

    //线程池

    //事件触发模式
    server.InitEventMode_();

    //事件监听

    //运行服务器
}