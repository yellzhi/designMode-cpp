//
// Created by lzb on 2020/2/26.
//

#ifndef DESIGNMODE_COMPOSITE_HPP
#define DESIGNMODE_COMPOSITE_HPP
#include <iostream>
#include <vector>
using namespace std;
/*  组合模式
 * 我们PC用到的文件系统，其实就是我们数据结构里的树形结构，我们处理树中的每个节点时，其实不用考虑他是叶子节点还是根节
    点，因为他们的成员函数都是一样的，这个就是组合模式的精髓。他模糊了简单元素和复杂元素的概念，客户程序可以向处理简单元
    素一样来处理复杂元素,从而使得客户程序与复杂元素的内部结构解耦。
    将对象组合成树形结构以表示“部分-整体”的层次结构。组合模式使得用户对单个对象和组合对象的使用具有一致性。
    1.透明方式
        作为第一种选择，在Component里面声明所有的用来管理子类对象的方法，包括add（）、remove（），以及getChild（）方法。这
        样做的好处是所有的构件类都有相同的接口。在客户端看来，树叶类对象与合成类对象的区别起码在接口层次上消失了，客户端可以
        同等同的对待所有的对象。这就是透明形式的组合模式。这个选择的缺点是不够安全，因为树叶类对象和合成类对象在本质上是有区
        别的。树叶类对象不可能有下一个层次的对象，因此add（）、remove（）以及getChild（）方法没有意义，是在编译时期不会出错，
        而只会在运行时期才会出错或者说识别出来。
    2.安全方式
        第二种选择是在Composite类里面声明所有的用来管理子类对象的方法。这样的做法是安全的做法，因为树叶类型的对象根本就没有
        管理子类对象的方法，因此，如果客户端对树叶类对象使用这些方法时，程序会在编译时期出错。这个选择的缺点是不够透明，因为
        树叶类和合成类将具有不同的接口。这两个形式各有优缺点，需要根据软件的具体情况做出取舍决定。
 * */

class BaseNode{
public:
    virtual ~BaseNode(){ //cout << "delete node:"<< m_id <<endl;
    }
    BaseNode(int id):m_id(id){}
    virtual void Operation() const =0;
    int getId()const { return m_id;}
private:
    int m_id;
};

//组合
class Composite: public BaseNode{
public:
    ~Composite(){ for(auto &v: m_nodes) delete v; m_nodes.clear();}
    Composite(int id):BaseNode(id){}

    void add(BaseNode* node){ m_nodes.emplace_back(node);}
    BaseNode* getChild(size_t index){
        if(m_nodes.size() <= index)
            return nullptr;
        return m_nodes[index];
    }
    void remove(BaseNode* node){
        for(auto it = m_nodes.begin(); it!=m_nodes.end(); ++it){
            if((*it)->getId() == node->getId()){
                BaseNode* temp = node;
                m_nodes.erase(it);
                delete temp;
            }
        }
    }
    void Operation() const{
        cout << getId() <<" oparation..."<<endl;
        for(auto const&v:m_nodes){ v->Operation();}
    }
private:
    vector<BaseNode* >m_nodes;
};

#endif //DESIGNMODE_COMPOSITE_HPP
