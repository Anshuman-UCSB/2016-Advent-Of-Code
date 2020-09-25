#include <iostream>
#include <vector>
#include <fstream>
#define grid vector<vector<char>>

using namespace std;

struct Solver{
    grid m;
    int x, y;
    Solver(){}
    Solver(grid g){
        m = g;

        for(int j = 0;j<m.size();j++){
            for(int i = 0;i<m[j].size();i++){
                if(m[j][i] == 'S'){
                    x = i;
                    y = j;
                    goto out;
                }
            }
        }
        out:;

    }
};

struct Grid{
    grid m;
    int x, y;
    Grid(){
        
    }
};

grid read(){
    grid m;
    fstream file("input");
    string line;
    while(getline(file, line)){
        m.push_back(vector<char>());
        for(char c: line)
            m.back().push_back(c);
        m.back().pop_back();
    }
    return m;
}

void printGrid(grid& g){
    for(auto& r: g){
        for(auto c: r){
            cout<<c;
        }cout<<endl;
    }
}

int main(){
    grid g = read();
    printGrid(g);
    int mx = -1;
    for(auto& r: g)
        for(auto c: r)
            if(c>= '0' && c<='9')
                mx = max(mx, c-'0');
    
    
    
}