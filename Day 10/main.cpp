#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

void ASSERT(bool inp){
    if(!inp){
        exit(1);
    }
}

struct Cell{
    bool isBot = false;
    vector<int> data;
    string lowId, highId;
};

// bot 2 gives low to bot 1 and high to bot 0
// value 5 goes to bot 2

vector<string> parse(string line){
    vector<string> out;
    string a, b, temp;
    stringstream ss(line);
    ss>>temp;
    if(temp == "bot"){
        ss>>a;
        out.push_back(temp+a);
        ss>>a>>a>>a>>a>>b;
        out.push_back(a+b);
        ss>>a>>a>>a>>a>>b;
        out.push_back(a + b);
    }else{
        ss>>a>>temp>>temp>>temp>>b;
        out.push_back(a);
        out.push_back(temp+b);
    }
    return out;
}

void act(map<string, Cell>& m, string id) {
    if(m[id].isBot){
        if(m[id].data.size() == 2){
            int low = min(m[id].data[0], m[id].data[1]);
            int high = max(m[id].data[0], m[id].data[1]);
            if(low == 17 && high == 61){
                cout<<"Part 1 answer is "<<id<<endl;
            }
            m[m[id].lowId].data.push_back(low);
            cout << "Giving " << min(m[id].data[0], m[id].data[1])<<" from "<<id<<" to "<<m[id].lowId<<endl;
            m[m[id].highId].data.push_back(high);
            cout << "Giving " << max(m[id].data[0], m[id].data[1]) << " from " << id << " to " << m[id].highId << endl;
            m[id].data.clear();
            act(m, m[id].lowId);
            act(m, m[id].highId);
        }
    }
}

void setInstruction(map<string, Cell>& m, vector<string> inst){
    if(inst.size() == 3){
        m[inst[0]].lowId = inst[1];
        m[inst[0]].highId = inst[2];
        m[inst[0]].isBot = true;
        cout<<"For "<<inst[0]<<" set low to go to "<<inst[1]<<" and high to "<<inst[2]<<endl;
    }
}

vector<string> read(){
    fstream file("input");
    string line;
    vector<string> raw;
    while(getline(file, line)){
        raw.push_back(line);
    }
    return raw;
}

void print(map<string, Cell> &m){
    for(auto& p: m){
        cout<<p.first<<" : ";
        for(auto& d: p.second.data){
            cout<<d<<" ";
        }cout<<endl;
    }
}

int main(){
    map<string, Cell> m;
    vector<string> raw = read();

    for(auto& l: raw){
        setInstruction(m, parse(l));
    }

    for(auto& l: raw){
        vector<string> temp = parse(l);
        if(temp.size() == 2){
            m[temp[1]].data.push_back(stoi(temp[0]));
            cout<<"Giving value "<<temp[0]<<" to "<<temp[1]<<endl;
            act(m, temp[1]);
        }
    }
    print(m);
}