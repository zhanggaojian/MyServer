#include<iostream>
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

Config::Config(){
    PORT = 9001;//端口号
    TRIGMode = 0; //触发组合模式，默认=listenfd LT+connfd LT
    LISTENTriMode = 0;//listenfd，默认LT
    CONNTrigMode = 0;//connfd，默认LT
    OPT_LINGER = 0;//优雅关闭连接，默认不使用
    sql_num = 8;//数据库连接池数量，默认8
    thread_num = 8;//线程池的数量，默认 8
    actor_model = 0;//并发模型，默认是proactor
}

void Config::parse_arg(){
    
}