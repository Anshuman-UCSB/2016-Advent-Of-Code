#include <utility>
#include <iostream>
#include <vector>
#include <stack>
#include "md5.h"

using namespace std;

struct State{
    string name;
    int x, y;
    State(string n, int xIn, int yIn) :name(n), x(xIn), y(yIn) {};
    State(){};
};

int main(){
    stack<State> s;
    string base = "awrkjxxr";
    State t;
    string hash;
    s.push(State(base, 0, 0));
    int mx = -1;
    int temp;
    string p1 = "null";
    while(!s.empty()){
        t = s.top();
        s.pop();
        // cout<<t.x<<", "<<t.y<<" - "<<t.name<<endl;
        hash = md5(t.name);
        if(t.x == 3 && t.y == 3){
            temp = t.name.size() - base.size();
            // cout<<"path"<<endl;
            // if(p1 == "null" || p1.size() > t.name.size()){
            //     p1 = t.name;
            //     cout<<"New shortest: "<<p1<<endl;
            // }
            if(temp > mx){
                mx = temp;
                
                // cout<<"Valid path ("<<mx<<") - "<<t.name<<endl;
            }
            // break;
        }
        else{
            if(hash[0] >= 'b' && t.y>0){
                s.push(State(t.name+"U", t.x, t.y-1));
            }
            if(hash[1] >= 'b' && t.y<3){
                s.push(State(t.name+"D", t.x, t.y+1));
            }
            if(hash[2] >= 'b' && t.x>0){
                s.push(State(t.name+"L", t.x-1, t.y));
            }
            if(hash[3] >= 'b' && t.x<3){
                s.push(State(t.name+"R", t.x+1, t.y));
            }
        }
    }
    cout<<"part 2: "<<mx<<endl;
}   