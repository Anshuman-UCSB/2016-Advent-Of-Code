#include "md5.h"
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
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
    queue<State> q;
    q.push(State(0,0,pass));
    int mx = -1;
    int size;
    while(!q.empty()){
        // cout<<q.size()<<endl;
        State front = q.front();
        q.pop();
        if(front.x == 3 && front.y == 3){
            size = front.hash.size()-pass.size();
            if(size > mx){
                mx = size;
                cout<<"New max size "<<mx<<" found with path "<<front.hash<<endl;
            }
            // cout<<"(mx = "<<mx<<") Valid path - "<<front.hash<<endl;
        }else{
            for(auto &s:front.getBranches()){
                q.push(s);
            }
        }
    }
}