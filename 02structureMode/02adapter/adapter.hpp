//
// Created by lzb on 2020/2/26.
//

#ifndef DESIGNMODE_ADAPTER_HPP
#define DESIGNMODE_ADAPTER_HPP

#include <iostream>
using namespace std;
/*
 *适配器模式把一个类的接口变换成客户端所期待的另一种接口，从而使原本接口不匹配而无法在一起工作的两个类能够在一起工作。
    比如说我的hp笔记本，美国产品，人家美国的电压是110V的，而我们中国的电压是220V，要在中国能使用，必须找个变压器转一下
    电压才可以。这个变压器就是个适配器。适配器模式有类适配器和对象适配器两种模式，我们将分别讨论。
思想：将一个类的接口转换成另外一个接口，使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。
场景：该模式的应用场景太多了，很多需要的功能模块的接口和我们需要的不完全一致或者有多余或不足，但是需要和我们的系统
协同工作，通过Adapter把它包装一下就能让使它接口兼容了。适用以下几种情况：
1．系统需要使用现有的类，而此类的接口不符合系统的需要。
2．想要建立一个可以重复使用的类，用于与一些彼此之间没有太大关联的一些类，包括一些可能在将来引进的类一起工作。这些源类不一定有很复杂的接口。
3．（对对象适配器而言）在设计里，需要改变多个已有子类的接口，如果使用类的适配器模式，就要针对每一个子类做一个适配器，而这不太实际。
 * */

class Target{
public:
    virtual void request(){}
};
class Adaptee{
public:
    void otherRequest(){
        cout << " Adaptee's request..."<<endl;
    }
};

///类适配器
class Adepter:public Target, Adaptee{
public:
    void request(){
        this->otherRequest();
    }
};

/// 对象适配器
class Adapter1:public Target{
public:
    void request(){
        m_adaptee.otherRequest();
    }
private:
    Adaptee m_adaptee;
};

#endif //DESIGNMODE_ADAPTER_HPP
