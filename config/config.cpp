#include "config.h"

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

void Config::parse_arg(int argc,char* argv[]){
    int opt;
    const char *str = "p:m:o:s:t:a:";
    while((opt=getopt(argc,argv,str))!=-1){
        switch(opt){
            case 'p':{//optarg表示的是当前选项的参数字符串
                PORT = atoi(optarg);
                break;
            }

            case 'm':{
                TRIGMode = atoi(optarg);
                break;
            }

            case 'o':{
                OPT_LINGER=atoi(optarg);
                break;
            }

            case 's':{
                sql_num=atoi(optarg);
                break;
            }

            case 't':{
                thread_num=atoi(optarg);
                break;
            }

            case 'a':{
                actor_model=atoi(optarg);
                break;
            }
        }
    }
}