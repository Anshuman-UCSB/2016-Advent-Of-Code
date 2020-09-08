#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct disk{
    int limit, pos;
    disk(){
        limit = -1;
        pos = -1;
    }
    disk(string inp){
        stringstream ss(inp);
        string t;
        ss>>t;
        limit = stoi(t);
        ss>>t;
        pos = stoi(t);
    }
    void incr(){
        pos++;
        pos = pos%limit;
    }
};

void incrVector(vector<disk>& v){
    for(int i = 0;i<v.size();i++){
        v[i].incr();
    }
}

bool valid(vector<disk>& v){
    for(auto& d:v){
        if(d.pos != 0){
            return false;
        }
    }
    return true;
}

int main(){
    //Disc #1 has 7 positions; at time=0, it is at position 0.
    fstream file("input");
    string line;
    vector<disk> discs;
    while(getline(file,line)){
        discs.push_back(disk(line));
    }

    for(int i = 0;i<discs.size();i++){
        for(int j = i;j<discs.size();j++){
            discs[j].incr();
        }
    }

    for(int i = 0;i<discs.size();i++){
        cout<<i<<" - "<<discs[i].pos<<" -> "<<discs[i].limit<<endl;
    }

    int time;
    for(time = 0;!valid(discs);time++){
        // cout<<"time "<<time<<endl;
        incrVector(discs);
    }
    cout<<"At time "<<time<<" you can successfully win."<<endl;
    for(int i = 0;i<discs.size();i++){
        cout<<i<<" - "<<discs[i].pos<<" -> "<<discs[i].limit<<endl;
    }
}