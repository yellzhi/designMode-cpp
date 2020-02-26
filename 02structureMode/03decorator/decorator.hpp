//
// Created by lzb on 2020/2/26.
//

#ifndef DESIGNMODE_DECORATOR_HPP
#define DESIGNMODE_DECORATOR_HPP

#include <iostream>
using namespace std;
/*
 * 装饰模式提供了更加灵活的向对象添加职责的方式。可以用添加和分离的方法，用装饰在运行时刻增加和删除职责。装饰模式提供了
    一种“即用即付”的方法来添加职责。它并不试图在一个复杂的可定制的类中支持所有可预见的特征，相反，你可以定义一个简单的
    类，并且用装饰类给它逐渐地添加功能。可以从简单的部件组合出复杂的功能。
    装饰器模式就是基于对象组合的方式，可以很灵活的给对象添加所需要的功能。它把需要装饰的功能放在单独的类中，并让这个类包
    装它所要装饰的对象，动态的给一个对象添加一些额外的职责。就增加功能来说，Decorator模式相比生成子类模式更为灵活。
 * */
///手机基类
class Phone{
public:
    virtual ~Phone(){}
    virtual void showMessage() =0;
    Phone(){}
    Phone(string const& _name):m_name(_name){}
protected:
    string m_name;
};

class IPhone:public Phone{
public:
    IPhone(string const& _name):Phone(_name){}
    void showMessage(){ std::cout <<m_name << endl; }
};
class AndroidPhone:public Phone{
public:
    AndroidPhone(string const& _name):Phone(_name){}
    void showMessage(){ std::cout <<m_name << endl; }
};

///手机装饰器
class CDecorator:public Phone{
public:
    virtual ~CDecorator(){ if(m_phone) delete m_phone;}
    CDecorator(Phone* phone){ m_phone = phone;}
    virtual void showMessage(){
        m_phone->showMessage();
    }
private:
    Phone* m_phone;
};

///手机挂件装饰器
class PendanDecrator: public CDecorator{
public:
    PendanDecrator(Phone* phone):CDecorator(phone){}
    virtual void showMessage(){
        CDecorator::showMessage();
        addMessage("饰品1");
    }
private:
    void addMessage(string const& ms){ cout << "添加挂件："<<ms<<endl;}
};
///手机膜装饰器
class MoDecrator: public CDecorator{
public:
    MoDecrator(Phone* phone):CDecorator(phone){}
    virtual void showMessage(){
        CDecorator::showMessage();
        addMessage("蓝光膜");
    }
private:
    void addMessage(string const& ms){ cout << "添加膜："<<ms<<endl;}
};




#endif //DESIGNMODE_DECORATOR_HPP
