#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    vector<vector<char>> mp;
    mp.push_back(vector<char>{' ', ' ', ' ', ' ', ' ', ' ', ' '});
    mp.push_back(vector<char>{' ', ' ', ' ', '1', ' ', ' ', ' '});
    mp.push_back(vector<char>{' ', ' ', '2', '3', '4', ' ', ' '});
    mp.push_back(vector<char>{' ', '5', '6', '7', '8', '9', ' '});
    mp.push_back(vector<char>{' ', ' ', 'A', 'B', 'C', ' ', ' '});
    mp.push_back(vector<char>{' ', ' ', ' ', 'D', ' ', ' ', ' '});
    mp.push_back(vector<char>{' ', ' ', ' ', ' ', ' ', ' ', ' '});

    fstream file("input");
    string line;
    vector<string> inp;
    while(getline(file,line)){
        inp.push_back(line);
    }


    vector<char> password;
    pair<int,int> pos(2,2);
    for(auto& line: inp){
        for(auto& c: line){
            switch(c){
                case 'U':
                    if(mp[pos.first-1][pos.second] != ' '){
                        pos.first--;
                    }
                    break;
                case 'R':
                    if (mp[pos.first][pos.second+1] != ' ')
                    {
                        pos.second++;
                    }
                    break;
                case 'L':
                    if (mp[pos.first][pos.second-1] != ' ')
                    {
                        pos.second--;
                    }
                    break;
                case 'D':
                    if (mp[pos.first + 1][pos.second] != ' ')
                    {
                        pos.first++;
                    }
                    break;
            }
        }
        password.push_back(mp[pos.first][pos.second]);
    }
    for(auto& p:password){
        cout<<p;
    }cout<<endl;
    
}