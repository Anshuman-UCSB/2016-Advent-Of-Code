#include <iostream>
#include <map>
#include <vector>
#include <utility>
#define input 10
// #define input 1352
using namespace std;

bool isWall(int x, int y){
    long val = x*x + 3 * x + 2 * x * y + y + y * y + input;
    bool wall = false;
    while(val){
        if(val%2){
            wall = !wall;
        }
        val/=2;
    }
    return wall;
}

vector<vector<int>> generate(int inp, int size){
    vector<vector<int>> m;
    for(int i = 0;i<size;i++)
        m.push_back(vector<int>(size));

    for(int y = 0;y<size;y++)
        for(int x = 0;x<size;x++)
            m[y][x] = -1*isWall(x,y)-1;

    return m;
}

void print(vector<vector<int>> m){
    for(auto& r: m){
        for(auto c:r){
            if(c == -1){
                cout<<".";
            }else if (c == -2)
            {
                cout<<"#";
            }
            
        }cout<<endl;
    }
}

int main(){
    vector<vector<int>> m = generate(10, 25);
    print(generate(10, 25));
    
}