//
// Created by lzb on 2020/2/26.
//
#include <iostream>
#include "composite.hpp"
using namespace std;

int main(){

    Composite com(0);
    com.add(new Composite(1));
    com.add(new Composite(5));
    com.add(new Composite(16));
    com.add(new Composite(8));

    com.Operation();
    com.remove(com.getChild(2));
    cout << "***************"<<endl;
    return 1;
}
