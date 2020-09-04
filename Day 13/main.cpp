#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#define input 1352
using namespace std;

bool isWall(int x, int y){
    long temp = x*x + 3*x + 2*x*y + y + y*y + input;
    bool wall = false;
    while(temp){
        if(temp%2){
            wall = !wall;
        }
        temp/=2;
    }
    return wall;

}

struct Coord{
    bool wall;
    int dist;
    Coord(){
        wall = false;
        dist = -1;
    }
    Coord(int x, int y, int dist){
        wall = isWall(x,y);
        if(!wall){
                this->dist = dist;
        }else{
            this->dist = -1;
        }
    }

};

void printMap(map<pair<int, int>, Coord>& m){
    int mX(0), mY(0);
    for(auto& p: m){
        // cout<<p.first.first<<", "<<p.first.second<<endl;
        mX = max(mX, p.first.first);
        mY = max(mY, p.first.second);
    }
    for(int i = 0;i<mX;i++){
        cout<<"-";
    }cout<<endl;
    for(int y = 0;y<=mY;y++){
        for(int x = 0;x<=mX;x++){
            // cout<<"Printing "<<x<<", "<<y<<endl;
            if(m.count(make_pair(x,y))){
                if(m[make_pair(x,y)].wall){
                    cout<<"#";
                }else{
                    cout<<m[make_pair(x,y)].dist%10;
                }
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    string trash;
    map<pair<int, int>, Coord> m;
    int dist = 0;
    m[make_pair(1,1)] = Coord(1,1,dist);
    
    printMap(m);
    while(m.count(make_pair(31,39)) == 0){
        for(auto& p:m){
            if(p.second.dist == dist){
                int x = p.first.first;
                int y = p.first.second;
                if(m.count(make_pair(x+1,y)) == 0){
                    m[make_pair(x+1,y)] = Coord(x+1,y, dist+1);
                }
                if(m.count(make_pair(x,y+1)) == 0){
                    m[make_pair(x,y+1)] = Coord(x,y+1, dist+1);
                }
                if(x-1 >= 0 && m.count(make_pair(x-1,y)) == 0){
                    m[make_pair(x-1,y)] = Coord(x-1,y, dist+1);
                }
                if(y-1 >= 0 && m.count(make_pair(x,y-1)) == 0){
                    m[make_pair(x,y-1)] = Coord(x,y-1, dist+1);
                }
                
            }
        }
        dist++;
        cout<<"\033[2J";
        printMap(m);
        // cin>>trash;
    }

    cout<<"\nIt took "<<m[make_pair(31,39)].dist<<" steps."<<endl;
}