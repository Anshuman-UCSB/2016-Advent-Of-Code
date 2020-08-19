#include "bot.h"

void Bot::addData(int val){
    data.push_back(val);
    assert(data.size()<=2);
    if(data.size() == 2){
        if(data[0]>data[1]){
            swap(data[0],data[1]);
        }
    }
}

void Bot::give(Bot &b1, Bot &b2){
    static_assert(data.size() == 2);
    b1.addData(data[0]);
    b2.addData(data[1]);
    data.pop_back();
    data.pop_back();
}


