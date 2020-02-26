//
// Created by lzb on 2020/2/26.
//

#ifndef DESIGNMODE_BUILDER_HPP
#define DESIGNMODE_BUILDER_HPP
#include <iostream>
using namespace std;
/*
 * Builder模式是将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。Builder模式和AbstractFactory模式在功能上很相似，
 * 因为都是用来创建大的复杂的对象，它们的区别是：Builder模式强调的是一步步创建对象，并通过相同的创建过程可以获得不同的结果对象，
 * 一般来说Builder模式中对象不是直接返回的。而在AbstractFactory模式中对象是直接返回的，AbstractFactory模式强调的是为创建多个相互依赖的对象提供一个同一的接口。
适用于以下情况:
    1)当创建复杂对象的算法应该独立于该对象的组成部分以及它们的装配方式时。
    2)当构造过程必须允许被构造的对象有不同的表示时

    思想：将一个类创建过程和他的主体部分分离。

场景：该模式的典型的应用场景是：一个类的创建过程可能比较复杂，
    或者创建过程中的某些阶段可能会容易变化；或者多个类的创建过程比较类似， 但是主体不同。

实现：在 以上提到的两种场景中，我们就可以取出一个类的创建过程的代码，定义一个专门的Builder类，
    而在原来创建类对象实例的地方，将这个Builder类的实例作为参数传入。
    还有第二个重点，就是Builder类 可以将将整个创建过程分为几个阶段，每个阶段不必在类中直接实现，而可以通过继承体系在子类中实现，
    或者通过子类的方法过载来修改创建过程中的某个阶段， 但是重用其他的阶段。可以发现，该模式将一个对象的复杂创建过程重用到非常高的层次。
    这正是它的意义所在。
 * */

class Car{ ///car 基类 定义基本属性
public:
    Car(){}
    ~Car(){}
    void setWhell(string const& _whell){ m_whell = _whell;}
    void setColor(string const& _color){ m_color = _color;}
    void setId(string const& _id){ m_id = _id;}
    void disPlay(){
        cout << "whell:"<< m_whell << "  color:"<< m_color << " id:"<< m_id <<endl;
    }
private:
    string m_whell;
    string m_color;
    string m_id;
};

class CarBuilder{ /// 构造真抽象基类，定义构造接口
public:
    virtual ~CarBuilder(){ if (m_car) delete m_car;}
    virtual void setWhell() = 0;
    virtual void setColor() = 0;
    virtual void setId() = 0;
    Car* getCar() { return m_car;}
protected:
    CarBuilder(){ m_car = new Car();}
private:
    Car* m_car;
};

class CarDirector{
public:
    /// 创建框架(稳定)
    Car* CreatCar(CarBuilder* p_car_builder){
        if(p_car_builder){
            p_car_builder->setWhell();
            p_car_builder->setColor();
            p_car_builder->setId();
            return p_car_builder->getCar();
        }
        return nullptr;
    }
};

class CarABuild :public CarBuilder{ ///car A
public:
    ~CarABuild(){}
    ///car A 构造过程，自定义
    void setWhell(){ getCar()->setWhell("whell_A");}
    void setColor(){ getCar()->setColor("color_A");}
    void setId(){ getCar()->setId("id_A");}
};
class CarBBuild :public CarBuilder{
public:
    ~CarBBuild(){}
    void setWhell(){ getCar()->setWhell("whell_B");}
    void setColor(){ getCar()->setColor("color_B");}
    void setId(){ getCar()->setId("id_B");}
};





#endif //DESIGNMODE_BUILDER_HPP
