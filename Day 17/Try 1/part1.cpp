#include "md5.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool isOpen(char inp){
    return inp>='b';
}

struct State{
    int x, y;
    string hash;
    State(){
        hash = "";
    }
    State(const State& old){
        x = old.x;
        y = old.y;
        hash = old.hash;
    }
    State(int x, int y, string hsh){
        this->x = x;
        this->y = y;
        hash = hsh;
    }
    
    vector<State> getBranches(){
        string md = md5(hash);
        vector<State> out;
        if(isOpen(md[0])){
            // cout<<"up works"<<endl;
            if(y>0)
                out.push_back(State(x, y-1,hash+"U"));
        }
        if(isOpen(md[1])){
            // cout<<"down works"<<endl;
            if(y<4)
                out.push_back(State(x, y+1,hash+"D"));
        }
        if(isOpen(md[2])){
            // cout<<"left works"<<endl;
            if(x>0)
                out.push_back(State(x-1, y,hash+"L"));
        } 
        if(isOpen(md[3])){
            // cout<<"right works"<<endl;
            if(x<4)
                out.push_back(State(x+1, y,hash+"R"));
        } 
        return out;
    }
};


int main(){
    string pass = "awrkjxxr";
    vector<State> queue, temp;
    queue.push_back(State(0, 0, pass));
    int stage = 0;
    bool first = true;
    while(true){
        cout<<"Starting again, with queue size "<<queue.size()<<endl;
        for(auto& s: queue){
            // cout<<stage<<" - "<<s.hash<<endl;
            if(s.x == 3 && s.y == 3){
                if(first){
                    cout<<"Valid path found on stage "<<stage<<": "<<s.hash<<endl;
                    first = false;
                }
            }else{
                vector<State> next = s.getBranches();
                temp.insert(end(temp), begin(next), end(next));
            }
        }
        cout<<"Starting again, with temp size "<<temp.size()<<endl;
        queue = temp;
        temp.clear();
        stage++;//DDUDRLRRUDRD
        first = true;
    }
    
}