#ifndef CONFIG_H
#define CONFIG_H

#include<iostream>
#include<unistd.h>
using namespace std;

class Config{
public:
    Config();
    ~Config(){}
    void parse_arg(int argc,char* argv[]);

    int PORT;//端口号
    int TRIGMode;//触发模式
    int LISTENTriMode;//listenfd触发模式
    int CONNTrigMode;//connfd触发模式
    int OPT_LINGER;//优雅关闭连接
    int sql_num;//数据库连接池数量
    int thread_num;//线程池线程数量
    int actor_model;//并发模型选择
};
#endif