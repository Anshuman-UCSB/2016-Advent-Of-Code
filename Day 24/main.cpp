#include <iostream>
#include <utility>
#include <algorithm>
#include <map>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct coord{
    pair<int, int> crd;
    int step;
    coord(){}
    coord(int x, int y, int step){
        crd = make_pair(x,y);
        this->step = step;
    }
    coord(pair<int, int> t, int s): crd(t), step(s){}
    friend ostream &operator<<( ostream &output, const coord &D ) { 
        output << "("<<D.crd.first<<", "<<D.crd.second<<"), S: "<<D.step;
        return output;            
    }
};


void print(vector<vector<int>>& m){
    for(auto& r: m){
        for(auto c: r){
            switch(c){
                case -1:
                    cout<<' ';
                    break;
                case -2:
                    cout<<'#';
                    break;
                case -3:
                    cout<<'.';
                    break;
                default:
                    cout<<c;
                    break;
            }
        }
        cout<<endl;
    }
}

int solve(vector<string>& raw, int start, int end){
    vector<vector<int>> m;
    for(auto& l: raw){
        m.push_back(vector<int>());
        for(auto c: l){
            if(c == '.'){
                m.back().push_back(-1);
            }else if(c == '#'){
                m.back().push_back(-2);
            }else if(c == '0'+start || c == '0'+end){
                m.back().push_back(c-'0');
            }else{
                m.back().push_back(-1);
            }
        }
    }

    coord sCoord;
    for(int y =0;y<m.size();y++){
        for(int x = 0;x<m[y].size();x++){
            if(m[y][x] == start){
                sCoord = coord(x,y,0);
                goto out;
            }
        }
    }
    out:;

    queue<coord> q;
    q.push(sCoord);
    bool done = false;
    while(!done || q.empty()){
        coord temp = q.front();
        q.pop();
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        for(int i = 0;i<4;i++){
            if(m[temp.crd.second+dy[i]][temp.crd.first+dx[i]] == -1){
                q.push(coord(temp.crd.first+dx[i],temp.crd.second+dy[i], temp.step+1));
                m[temp.crd.second+dy[i]][temp.crd.first+dx[i]] = -3;
            }else if(m[temp.crd.second+dy[i]][temp.crd.first+dx[i]] == end){
                return temp.step+1;
            }
        }
    }

    return -1;   
    
}

int main(){
    fstream file("input");
    string line;
    vector<string> raw;
    while(getline(file, line)){
        raw.push_back(line);
        raw.back().pop_back();
    }
    map<pair<int, int>, int> dist;
    int nodes = 7;
    for(int i = 0;i<nodes;i++){
        for(int j = i+1;j<=nodes;j++){
            int val = solve(raw, i, j);
            dist[make_pair(i, j)] = val;
            dist[make_pair(j, i)] = val;
        }
    }

    vector<int> path;
    for(int i = 0;i<=nodes;i++)
        path.push_back(i);
    path.push_back(0);
    int p1 = INT32_MAX;
    vector<int> minPath;
    do{
        int sum = 0;
        for(int i =0;i<path.size()-1;i++)
            sum+=dist[make_pair(path[i],path[i+1])];
        
        if(sum<p1){
            p1 = sum;
            minPath = path;
        }
    }while(next_permutation(path.begin()+1,path.end()-1));
    cout<<p1<<endl;
}