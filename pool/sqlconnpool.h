#ifndef SQLCONNPOOL_H
#define SQLCONNPOOL_H

#include <iostream>
#include <mysql/mysql.h>
#include <list>
using namespace std;

class SqlConnPool{
public:
    //单例模式
    static SqlConnPool* GetInstance();

    //sql init
    void SqlInit(string host,int port,string user,string pwd,string dbname,int connSize);

    //从数据库连接池中获取一个可用的数据库连接
    MYSQL *GetConn();

    //释放数据库连接
    void FreeConn();

    //获取空余连接的数量
    int GetFreeConnNum();

    //关闭所有连接,为什么需要这个
    void ClosePool();
private:
    SqlConnPool();
    ~SqlConnPool();

    int m_maxConn;//最大连接数
    int m_curConn;//当前使用的连接数
    int m_FreeConn;//剩余的连接数

    list<MYSQL *> connList; 
public:
    string m_host;//主机地址
    string m_user;//数据库登录用户名
    string m_passwd;//数据库登录密码
    string m_databasename;
    int m_port;//数据库端口号
};

#endif