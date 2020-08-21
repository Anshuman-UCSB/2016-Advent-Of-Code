#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void assert(bool inp){
    if(!inp){
        exit(1);
    }
}

struct Cell{
    string id;
    string lowTarget, highTarget;
    vector<int> data;

    Cell(){
        id = "Null";
    }

    Cell(string inp){
        id = inp;
    }

    void setId(string id){
        this->id = id;
    }    

    void giveData(int dat){
        data.push_back(dat);
    }

    void setLow(string low){
        lowTarget = low;
    }

    void setHigh(string high){
        highTarget = high;
    }

    void act(map<string, Cell>& m){
        if(data.size() == 2 && id[0] == 'b'){
            m[lowTarget].giveData(min(data[0],data[1]));
            m[highTarget].giveData(max(data[0], data[1]));
            data.clear();
            m[lowTarget].act(m);
            m[highTarget].act(m);
        }
    }
};

void instructionLine(map<string, Cell> &m, string line){
    //bot 2 gives low to bot 1 and high to bot 0
    stringstream ss(line);
    string temp, temp2;
    string trash;
    ss>>temp>>temp2;
    assert(temp == "bot");

    string botId, lowId, highId;
    botId = temp+temp2;
    m[botId].setId(botId);
    ss>>trash>>trash>>trash>>temp>>temp2;
    lowId = temp+temp2;
    ss>>trash>>trash>>trash>>temp>>temp2;
    highId = temp+temp2;
    m[botId].setLow(lowId);
    m[lowId].setId(lowId);
    m[botId].setHigh(highId);
    m[highId].setId(highId);
}

void valueLine(map<string, Cell> &m, string line) {
    //value 2 goes to bot 2
    stringstream ss(line);
    string trash, temp, temp2;
    int val;
    string id;
    ss>>trash>>temp;
    id = stoi(temp);
    ss>>trash>>trash>>temp>>temp2;
    id = temp+temp2;
    m[id].setId(id);
    m[id].giveData(val);
    m[id].act(m);
}


int main() {
    map<string, Cell> m;
    fstream file("input");
    string line;
    vector<string> raw;
    while(getline(file,line)){
        raw.push_back(line);
    }
    for(string& l: raw){
        if(l[0]=='b'){
            instructionLine(m, l);
        }
    }
    for (string& l : raw) {
        if (l[0] == 'v') {
            valueLine(m, l);
        }
    }
    for(auto& p:m){
        cout<<p.first<<" - "<<p.second.lowTarget << " < "<<p.second.highTarget<<" - ";
        for(auto& d:p.second.data){
            cout<<d<<" ";
        }cout<<endl;
    }
}