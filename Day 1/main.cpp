#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <set>
using namespace std;
int main(){
    bool second = false;

    int loc[2] = {0,0};
    int dir = 0;
    fstream file("input.txt");
    string line;
    getline(file, line);
    stringstream ss(line);
    string token;
    set<pair<int,int> > st;
    while(ss>>token){
        if(token[0] == 'R'){
            dir = (dir+1)%4;
        }
        else{
            dir = (dir+3)%4;
        }
        if(token.back() == ','){
            token = token.substr(1,token.size()-2);
        }
        else{
            token = token.substr(1);
        }
        int dist = stoi(token);
        for(int i = 0;i<dist;i++){
            switch(dir){
                case 0:
                    loc[1]+=1;
                    break;
                case 1:
                    loc[0]+=1;
                    break;
                case 2:
                    loc[1]-=1;
                    break;
                case 3:
                    loc[0]-=1;
                    break;
            }
            if (!second && !st.insert(make_pair(loc[0], loc[1])).second)
            {
                cout << "Part 2: " << abs(loc[0]) + abs(loc[1]) << endl;
                second = true;
            }
        }
        // cout<<loc[0]<<", "<<loc[1]<<endl;
        
        // for(auto& e: st){
        //     cout<<e.first<<", "<<e.second<<endl;
        // }
    }   
    
    cout<<"Part 1: "<<abs(loc[0])+abs(loc[1])<<endl;
    
}