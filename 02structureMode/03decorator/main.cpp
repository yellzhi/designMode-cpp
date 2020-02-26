//
// Created by lzb on 2020/2/26.
//
#include <iostream>
#include "decorator.hpp"
using namespace std;

int main(){
    Phone *iphone = new IPhone("iphone");
    iphone = new PendanDecrator(iphone);
    iphone = new MoDecrator(iphone);
    iphone->showMessage();

    Phone* aphone = new AndroidPhone("android");
    aphone = new MoDecrator(aphone);
    aphone->showMessage();

    return 1;
}

