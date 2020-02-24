//
// Created by lzb on 2020/2/24.
//

#ifndef DESIGNMODE_FACTORY_HPP
#define DESIGNMODE_FACTORY_HPP

#include <iostream>
using namespace std;
///产品基类
class Product{
public:
    virtual ~Product() {};

protected:
    Product() {};
};

class ConcreateProduct : public Product{
public:
    ~ConcreateProduct(){}
    ConcreateProduct(){
        cout<< "ConcreateProduct ..." <<endl;
    }
};

///工厂接口
class Factory{
public:
    virtual ~Factory() {};
    Factory() {}
    virtual Product* CreateProduct() =0;
    virtual void run() =0;
};

class ConcreateFactory : public Factory{
public:
    ~ConcreateFactory(){}
    ConcreateFactory(){
        cout << " ConcreateProduct ..." <<endl;
    }
    Product* CreateProduct(){
        return new ConcreateProduct();
    }
    void run(){
        cout << "ConcreateFactory run ..." <<endl;
    }

};

/****************************** AbstractFactory ************************************************************************/
/// product
class AbstractProductA{
public:
    virtual ~AbstractProductA(){}
protected:
    AbstractProductA(){}
};
class AbstractProductB{
public:
    virtual ~AbstractProductB(){}
protected:
    AbstractProductB(){}
};

class ProductA1: public AbstractProductA{
public:
    ProductA1(){
        cout << " product A1 ..." <<endl;
    }
    ~ProductA1(){}
};
class ProductA2: public AbstractProductA{
public:
    ProductA2(){
        cout << " product A2 ..." <<endl;
    }
    ~ProductA2(){}
};
class ProductB1: public AbstractProductB{
public:
    ProductB1(){
        cout << " product B1 ..." <<endl;
    }
    ~ProductB1(){}
};
class ProductB2: public AbstractProductB{
public:
    ProductB2(){
        cout << " product B2 ..." <<endl;
    }
    ~ProductB2(){}
};

/// factory
class AbstractFactory{
public:
    virtual ~AbstractFactory(){}
    virtual AbstractProductA* CreateProductA() =0;
    virtual AbstractProductB* CreateProductB() =0;
protected:
    AbstractFactory(){}
};

class ProductFActory1: public AbstractFactory{
    AbstractProductA* CreateProductA(){
        cout << "factory1 get ProductA1 ..." <<endl;
        return new ProductA1();
    }
    AbstractProductB* CreateProductB(){
        cout << "factory1 get ProductB1 ..." <<endl;
        return  new ProductB1();
    }
};
class ProductFActory2: public AbstractFactory{
    AbstractProductA* CreateProductA(){
        cout << "factory2 get ProductA2 ..." <<endl;
        return new ProductA2();
    }
    AbstractProductB* CreateProductB(){
        cout << "factory2 get ProductB2 ..." <<endl;
        return  new ProductB2();
    }
};




#endif //DESIGNMODE_FACTORY_HPP
