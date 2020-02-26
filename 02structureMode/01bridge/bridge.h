//
// Created by lzb on 2020/2/26.
//

#ifndef DESIGNMODE_BUILDER_H
#define DESIGNMODE_BUILDER_H

#include <iostream>
using namespace std;

/*
 *  桥接模式：将抽象部分与实现部分分离，使它们都可以独立的变化。
    主要解决：在有多种可能会变化的情况下，用继承会造成类爆炸问题，扩展起来不灵活。
    何时使用：实现系统可能有多个角度分类，每一种角度都可能变化。
 * */
class ISport{
public:
    virtual ~ISport(){}
    virtual void do_sport(int time) =0;
};
class swimSport:public ISport{
public:
    void do_sport(int time){
        cout << "swim " << time << "mins" << endl;
    }
};
class runSport:public ISport{
public:
    void do_sport(int time){
        cout << "run " << time << "mins"<< endl;
    }
};
class flySport:public ISport{
public:
    void do_sport(int time){
        cout << "fly " << time << "mins"<< endl;
    }
};

///桥接接口
class IBuilder{
public:
    virtual ~IBuilder(){}
    virtual void do_sport() = 0;
};

class Client :public IBuilder{
public:
    ~Client(){
        if (m_sport == nullptr) {
            delete m_sport;
            m_sport = nullptr;
        }
    }
    Client(int time, ISport* sport):m_time(time), m_sport(sport){
    }
    void do_sport(){
        if(m_sport)
            m_sport->do_sport(m_time);
    }
private:
    int m_time =0;
    ISport *m_sport = nullptr;
};

/******************************other eg*******************************************************/

///行为基类
class Action{
public:
    virtual void todo() =0;
};

class Write:public Action{
public:
    void todo(){
        cout << "to write..."<<endl;
    }
};
class Draw:public Action{
public:
    void todo(){
        cout << "to draw..."<<endl;
    }
};
///工具基类
class Pen{
public:
    virtual ~Pen(){ destory();}
    Pen():m_action(nullptr){}
    virtual void use() {if(m_action) m_action->todo();};
    void setAction(Action* action){ destory(); m_action = action;}
private:
    void destory(){ if(m_action) delete m_action;}
    Action *m_action;
};

class Pencil:public Pen{
public:
    void use(){ std::cout << "use Pencil"<<endl; Pen::use();}
};
class Brush:public Pen{
public:
    void use(){ std::cout << "use Brush"<<endl; Pen::use();}
};


#endif //DESIGNMODE_BUILDER_H
