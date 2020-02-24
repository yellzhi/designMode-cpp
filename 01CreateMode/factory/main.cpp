//
// Created by lzb on 2020/2/24.
//
#include <iostream>
#include "factory.hpp"
using namespace std;
/*
 * Factory 工厂模式
 * 1.定义创建对象的接口，封装了对象的创建
 * 2.使得具体化类的工作延迟到了子类中
 * 但是 Factory 模式仅仅局限于一类类（就是说 Product 是一类，有一个共同的基类），如果我们要
        为不同类的类提供一个对象创建的接口，那就要用 AbstractFactory 了
    1. AbstractFactory 模式就是用来解决这类问题的：要创建一组相关或者相互依赖的对象

    AbstractFactory 模式是为创建一组（有多类）相关或依赖的对象提
供创建接口，而 Factory 模式正如我在相应的文档中分析的是为一类对象提供创建接口或延
迟对象的创建到子类中实现。并且可以看到，AbstractFactory 模式通常都是使用 Factory 模
式实现

 * */
int main(){
    cout << "mode factory"<<endl;
    Factory* fac = new ConcreateFactory();
    fac->run();

    cout << "************abstractFactory*****************"<<endl;
    AbstractFactory* abFac1 = new ProductFActory1();
    AbstractFactory* abFac2 = new ProductFActory2();
    abFac1->CreateProductA();
    abFac1->CreateProductB();
    abFac2->CreateProductA();
    abFac2->CreateProductB();
    return 0;
}

