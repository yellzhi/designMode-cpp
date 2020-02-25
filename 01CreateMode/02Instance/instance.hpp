//
// Created by lzb on 2020/2/25.
//

#ifndef DESIGNMODE_INSTANCE_HPP
#define DESIGNMODE_INSTANCE_HPP

#include <iostream>
#include <mutex>
using namespace std;

/// 懒汉式
/*
 * 懒汉式的特点是延迟加载，比如配置文件，采用懒汉式的方法，
 * 顾名思义，懒汉么，很懒的，配置文件的实例直到用到的时候才会加载
 * */
class LazyInstance{
private:
    LazyInstance(){}
    class CMem{
        // 内存安全优化
    public:
        ~CMem(){
            cout << "start destory instance...";
            if(LazyInstance::m_p) {
                delete LazyInstance::m_p;
                cout << "destory instance...";
            }
        }
    };
public:
    static LazyInstance* GetInstance(){
        //线程
        if(!m_p) {
            std::mutex mt;
            mt.lock();
            if(!m_p)
                m_p = new LazyInstance();
            mt.lock();
        }
        return m_p;
    }
    void run(){
        m_num++;
        cout << "times:" << m_num <<endl;
    }
private:
    static LazyInstance* m_p;
    int m_num;
    CMem m_m;
};
LazyInstance*  LazyInstance::m_p = NULL;

///饿汉式 线程安全
class HungryInstance{
private:
    HungryInstance(){}
public:
    static HungryInstance* GetInstance(){
        static HungryInstance m_instance;
        return &m_instance;
    }
    void run(){
        m_num++;
        cout << "times:" << m_num <<endl;
    }

private:
    int m_num;
};

#endif //DESIGNMODE_INSTANCE_HPP
