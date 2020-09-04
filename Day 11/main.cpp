#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <utility>
#include <set>
#include <queue>

using namespace std;

struct State{
    vector<pair<int, int>> f;
    int elevator, step;
    State(){
        elevator = 1;
        step = 0;
    }
    State(const State& old){
        elevator = old.elevator;
        step = old.step;
        for(auto p: old.f){
            f.push_back(p);
        }
    }
    bool isValid(){
        for(auto& p: f){
            if(p.first != p.second){
                for(auto& t: f){
                    if(t.second == p.first){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    string toStr(){
        sort(f.begin(), f.end());
        stringstream ss;
        ss<<elevator<<"_";
        for(auto& p: f){
            ss<<p.first<<","<<p.second<<"_";
        }
        return ss.str();
    }
};

State example(){
    State s;
    s.f.push_back(make_pair(1,2));
    s.f.push_back(make_pair(1,3));
    return s;
}

State input(){
    State s;
    s.f.push_back(make_pair(1,1));
    s.f.push_back(make_pair(1,1));
    s.f.push_back(make_pair(1,1));
    s.f.push_back(make_pair(2,1));
    s.f.push_back(make_pair(2,1));
    s.f.push_back(make_pair(3,3));
    s.f.push_back(make_pair(3,3));
    return s;
}

vector<State> variation(State& s){
    vector<State> out;

    //ind, first
    vector<pair<int, bool>> moveable;
    for(int i = 0;i<s.f.size();i++){
        if(s.f[i].first == s.elevator){
            moveable.push_back(make_pair(i, true));
        }
        if(s.f[i].second == s.elevator){
            moveable.push_back(make_pair(i, false));
        }
    }
    if(s.elevator < 4){
        // can move up
        // move 1 item
        if(moveable.size() >= 1){
            for(auto& p: moveable){
                State n(s);
                if(p.second){
                    n.f[p.first].first++;
                }else{
                    n.f[p.first].second++;
                }
                n.elevator++;
                n.step++;
                if(n.isValid()){
                    out.push_back(n);
                }
            }
        }
        //move 2 items
        if(moveable.size() >= 2){
            for(int i =0;i<moveable.size()-1;i++){
                for(int j = 1;j<moveable.size();j++){
                    State n(s);
                    if(moveable[i].second){
                        n.f[moveable[i].first].first++;
                    }else{
                        n.f[moveable[i].first].second++;
                    }
                    if(moveable[j].second){
                        n.f[moveable[j].first].first++;
                    }else{
                        n.f[moveable[j].first].second++;
                    }
                    n.elevator++;
                    n.step++;
                    if(n.isValid()){
                        out.push_back(n);
                    }
                }
            }
        }
    }
    if(s.elevator > 1){
        // can move down
        // move 1 item
        if(moveable.size() >= 1){
            for(auto& p: moveable){
                State n(s);
                if(p.second){
                    n.f[p.first].first--;
                }else{
                    n.f[p.first].second--;
                }
                n.elevator--;
                n.step++;
                if(n.isValid()){
                    out.push_back(n);
                }
            }
        }
        //move 2 items
        if(moveable.size() >= 2){
            for(int i =0;i<moveable.size()-1;i++){
                for(int j = 1;j<moveable.size();j++){
                    State n(s);
                    if(moveable[i].second){
                        n.f[moveable[i].first].first--;
                    }else{
                        n.f[moveable[i].first].second--;
                    }
                    if(moveable[j].second){
                        n.f[moveable[j].first].first--;
                    }else{
                        n.f[moveable[j].first].second--;
                    }
                    n.elevator--;
                    n.step++;
                    if(n.isValid()){
                        out.push_back(n);
                    }
                }
            }
        }
    }

    return out;
}

int main(){
    set<string> seen;
    queue<State> tree;
    // tree.push(example());
    tree.push(input());
    seen.insert(tree.front().toStr());
    //initialization
    while(seen.find("4_4,4_4,4_4,4_4,4_4,4_4,4_4,4_") == seen.end()){
        auto variations = variation(tree.front());
        // cout<<"Checking step "<<tree.front().step<<endl;
        // cout<<"Variation of size "<<variations.size()<<endl;
        for(auto& s: variations){
            if(s.toStr() == "4_4,4_4,4_4,4_4,4_4,4_4,4_4,4_"){
                cout<<"Took "<<s.step<<" to finish"<<endl;
                goto end;
            }
            // cout<<s.toStr()<<endl;
            if(seen.insert(s.toStr()).second){
                tree.push(s);
            }
        }
        tree.pop();
        // cout<<endl;
    }
    end:;
}