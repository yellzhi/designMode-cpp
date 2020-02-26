//
// Created by lzb on 2020/2/26.
//
#include <iostream>
#include "bridge.h"
int main()
{
    IBuilder* client = nullptr;
    client = new Client(10,new runSport());
    client->do_sport();
    delete client;

    client = new Client(5, new flySport());
    client->do_sport();
    delete client;
    return 1;
}

