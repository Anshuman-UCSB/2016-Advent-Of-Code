#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

struct maze{
    vector<vector<int>> m;
    int dist;
    int path;
    maze(){}
    maze(vector<string> raw, char a, char b){
        for(auto& l: raw){
            m.push_back(vector<int>());
            for(auto c:l)
                m.back().push_back(c);
        }
        for(auto& r: m){
            for(auto& c: r){
                if(c == a){
                    c = '*';
                }else if(c == b){
                    c = '+';
                }else if(c >= '0' && c<='9'){
                    c = '.';
                }
            }
        }
        dist = 0;
        char curr = '*';
        while(true){
            dist++;
            for(int y = 0;y<m.size();y++){
                for(int x = 0;x<m[y].size();x++){
                    if(m[y][x] == curr){
                        if(y>0 && m[y-1][x] == '.'){
                            m[y-1][x] = '0'+dist;
                        }
                        if(y<m.size()-1 && m[y+1][x] == '.'){
                            m[y+1][x] = '0'+dist;
                        }
                        if(x>0 && m[y][x-1] == '.'){
                            m[y][x-1] = '0'+dist;
                        }
                        if(x<m[y].size()-1 && m[y][x+1] == '.'){
                            m[y][x+1] = '0'+dist;
                        }
                        if(m[y][x+1] == '+' || m[y][x-1] == '+' || m[y-1][x] == '+' || m[y+1][x] == '+'){
                            // cout<<dist<<endl;
                            path = dist;
                            goto out;
                        }
                    }
                }
            }
            curr = '0'+dist;
            // print();
        }
        out:;

    }
    

    void print(){
        cout<<endl;
        for(auto& l: m){
            for(auto c: l){
                cout<<c;
            }cout<<endl;
        }
    }
};

int main(){
    fstream file("input");
    string line;
    vector<string> r;
    while(getline(file, line)){
        r.push_back(line);
    }
    int nodeCount = 7;
    map<pair<int, int>, int> mp;
    for(int i = 0;i<=nodeCount-1;i++){
        for(int j = i+1;j<=nodeCount;j++){
            mp[make_pair(i,j)] = maze(r, i+'0', j+'0').path;
        }
    }
    for(auto& p: mp)
        cout<<p.first.first<<" -> "<<p.first.second<<" : "<<p.second<<endl;

    vector<int> path;
    for(int i = 0;i<=nodeCount;i++){
        path.push_back(i);
    }
    vector<int> minPath;
    int minVal = INT32_MAX;
    do{
        string sep = "";
        for(auto i: path){
            cout<<sep<<i;
            sep = " -> ";
        }cout<<" : ";
        int temp = 0;
        for(int i = 0;i<path.size()-1;i++){
            pair<int, int> p = make_pair(path[i],path[i+1]);
            if(p.first>p.second){
                swap(p.first,p.second);
            }
            // cout<<path[i]<<" -> "<<path[i+1]<<" = "<<mp[p]<<endl;
            temp+=mp[p];
        }
        if(temp<minVal){
            minPath = path;
            minVal = temp;
        }
        cout<<temp<<endl;
    } while(next_permutation(path.begin()+1,path.end()));
    cout<<"The answer is: "<<minVal<<endl;
}