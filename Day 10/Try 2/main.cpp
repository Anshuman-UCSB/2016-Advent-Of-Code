#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
using namespace std;

struct Cell{
    string id;
    vector<int> data;
    map<string, Cell> *network; //0x00004A45
    bool isOutput;

    string low;
    string high;

    Cell(){
        id = "NULL";
    }

    Cell(string id, map<string, Cell> *nw){
        isOutput = id[0] == 'o';
        this->id = id;
        data.clear();
        low = high = -1;
        network = nw;
    }

    Cell(string id, string low, string high, map<string, Cell> *nw) {
        isOutput = id[0] == 'o';
        this->id = id;
        this->low = low;
        this->high = high;
        network = nw;
        data.clear();
    }

    void giveData(int val){
        if(data.size()>2){
            cout<<"ASERT ISSUE FAILED"<<endl;
            exit(1);
        }
        data.push_back(val);
    }

    void update(){
        if(data.size() == 2){
            int a(min(data[0],data[1])), b(min(data[0],data[1]));
            (*network)[low].giveData(a);
            (*network)[high].giveData(b);
            if(!isOutput){
                (*network)[low].update();
                (*network)[high].update();
            }
        }
    }

};

vector<string> read(){
    vector<string> raw;
    fstream file("input");
    string line;
    while(getline(file, line))
        raw.push_back(line);
    return raw;
}


int main(){
    int a;
    string b, c;
    vector<string> raw = read();
    stringstream ss;
    map<string, Cell> *nw = new map<string, Cell>;

    for(auto& line: raw){
        cout<<"reading line: "<<line<<endl;
        ss = stringstream(line);
        ss>>line;
        if(line == "value"){
            ss>>line;
            a = stoi(line);
            ss>>line>>line>>line;
            if(line == "bot"){
                ss>>line;
                b = "bot"+line;
            }else{
                ss>>line;
                b = "output"+line;
            }
            (*nw)[b].giveData(a);
            (*nw)[b].update();
        }else{
            ss>>b>>line>>line>>line>>c>>line;
            string temp = "bot"+b;
            c = c+line;
            ss>>line>>line>>line>>b>>line;
            b = b+line;
            if((*nw)[temp].id == "NULL"){
                (*nw)[temp] = Cell(temp, c, b, nw);
            }else{
                cout<<"Redefine bot uh oh"<<endl;
            }
        }
    }

    for(auto& p: *nw){
        cout<<p.first<<endl;
    }

}