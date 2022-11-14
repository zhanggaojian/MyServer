#include<iostream>
#include "config.h"
#include "webserver.h"
using namespace std;

int main(int argc,char* argv[]){
    //命令行参数解析
    Config config;
    config.parse_arg(argc,argv);

    //
    WebServer server()
}