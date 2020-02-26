//
// Created by lzb on 2020/2/26.
//
#include <iostream>
#include "builder.hpp"
int main(){

    CarDirector director;
    director.CreatCar(new CarABuild())->disPlay();
    director.CreatCar(new CarBBuild())->disPlay();

    return 1;
//    IBuilder* client = 0;
//    client = new Client(5, new swimSport());
//    client->do_sport();
//    delete client;
//
//    client = new Client(6, new flySport());
//    client->do_sport();
//    delete client;
//
//    client = new Client(10, new runSport());
//    client->do_sport();
//    delete client;
//    return 1;
}


