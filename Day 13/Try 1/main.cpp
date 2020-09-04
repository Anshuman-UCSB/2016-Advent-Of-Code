#include <iostream>
#include <map>
#include <vector>
#include <utility>
#define input 10
// #define input 1352
using namespace std;
struct cls{
    map<pair<int, int>, bool> m;
    int x, y;

    cls(){
        x = y = 1;
    }

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

    void generate(int x, int y){
        pair<int, int> crd = make_pair(x, y); 
        if(m.count(crd) == 0){
            m[crd] = isWall(x, y);
        }
    }

    char getChar(int x, int y){
        if(m.count(make_pair(x, y))){
            return m[make_pair(x,y)]?'#':'.';
        }
        return ' ';
    }

    void update(){
        if(x>0)
            generate(x-1,y);
        if(y>0)
            generate(x,y-1);
        generate(x+1,y);
        generate(x,y+1);
    }

};


int main(){
    
    // cout<<isWall(0,2)<<endl;
}