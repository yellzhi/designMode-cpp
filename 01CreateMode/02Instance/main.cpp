//
// Created by lzb on 2020/2/25.
//
#include <iostream>
#include "instance.hpp"
using namespace std;

int main(){
    LazyInstance::GetInstance()->run();
    LazyInstance::GetInstance()->run();

    HungryInstance::GetInstance()->run();
    HungryInstance::GetInstance()->run();

    return 1;
}

