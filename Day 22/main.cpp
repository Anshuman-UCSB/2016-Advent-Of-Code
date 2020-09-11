#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>

#define coord pair<int, int>

using namespace std;

struct Node{
    coord c;
    int size;
    int used;
    int avail;
    Node(){}
    Node(int x, int y, int s, int u, int a): size(s), used(u), avail(a), c(make_pair(x, y)){}
    ///dev/grid/node-x0-y0     88T   67T    21T   76%

    string toString(){
        stringstream build("");
        build<<"("<<c.first<<", "<<c.second<<") s"<<size<<" u"<<used<<" a"<<avail;
        return build.str();
    }
    
};

void parse(map<coord, Node>& m, string line){
    /*
    /dev/grid/node-x23-y1    88T   64T    24T   72%
    */
    stringstream ss(line.substr(16));
    char t1, t2;
    int x, y, s, u, a;
    string temp;
    ss>>x>>t1>>t2>>y;
    ss>>temp;
    temp.pop_back();
    s = stoi(temp);
    ss>>temp;
    temp.pop_back();
    u = stoi(temp);
    ss>>temp;
    temp.pop_back();
    a = stoi(temp);

    m[make_pair(x, y)] = Node(x,y,s,u,a);    
}

bool exists(map<coord, Node>& m, coord c){
    return (m.count(c));
}

int main(){
    map<coord, Node> m;
    fstream file("input");
    string line;
    getline(file, line);
    getline(file, line);
    //Trash first 2 lines
    while(getline(file, line))
        parse(m, line);
    // for(auto& p: m)
    //     cout<<p.second.toString()<<endl;

    int part1 = 0;
    for(auto& p: m){
        if(p.second.used){
            for(auto& t: m){
                if(t.first != p.first){
                    if(p.second.used <= t.second.avail){
                        // cout<<"    Found 2 valid nodes: "<<endl<<p.second.toString()<<endl<<t.second.toString()<<endl;
                        // cout<<p.second.used<<" > "<<t.second.avail<<endl;
                        part1++;
                    }
                }
            }
        }
    }
    cout<<"Part 1: "<<part1<<endl;
    //800153 too high
}