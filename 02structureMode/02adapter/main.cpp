//
// Created by lzb on 2020/2/26.
//
#include <iostream>
#include "adapter.hpp"
int main(){

    Target *tar = new Adepter();
    tar->request();

    tar = new Adapter1();
    tar->request();
    return 1;
}

