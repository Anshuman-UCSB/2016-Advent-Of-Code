#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void part1();

int main() {
    part1();
}

struct room {
    string name;
    int id;
    string key;
    bool real;

    room(string inp) {
        name = "";
        key = "";
        int ind = 0;
        while (inp[ind] < '0' || inp[ind] > '9') {
            if(inp[ind] != '-'){
                name += inp[ind];
            }
            ind++;
        }
        string temp = "";
        for(int i = 0;i<3;i++){
            temp+=inp[ind+i];
        }
        id = stoi(temp);
        for(int i = inp.size()-7;i<inp.size()-2;i++){
            key+=inp[i];
        }

        int mp[26];
        for(int i = 0;i<26;i++){
            mp[i] = 0;
        }
        for(auto& c: name){
            mp[c-'a']++;
        }

        int mx = -1;
        for(int i =0 ;i<26;i++){
            mx = max(mx, mp[i]);
            // cout<<char(i+'a')<<": "<<mp[i]<<endl;
        }
        temp = "";
        char cTemp;
        while(temp.size()<5){
            for(int i = 0; i<26;i++){
                if(mp[i] == mx){
                    cTemp = i+'a';
                    temp+= cTemp;
                }
            }
            mx--;
        }

        temp = temp.substr(0,5);
        if (temp == key){
            real = true;
        }else{
            real = false;
        }
        // cout<<name<<endl;
        // cout<<id<<endl;
        // cout<<key<<endl;
        // cout<<temp<<endl<<endl;
    }
};

void part1() {
    vector<room> v;
    fstream file("input");
    string line;
    while (getline(file, line)) {
        v.push_back(room(line));
    }
    int sum = 0;
    for(auto& room: v){
        if(room.real){
            sum+=room.id;
        }
    }
    cout<<sum<<endl;
}