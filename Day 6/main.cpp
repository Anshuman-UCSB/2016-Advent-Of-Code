#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void part1(vector<string> inp);
void part2(vector<string> inp);

int main(){
    vector<string> raw;
    fstream file("input");
    string line;
    while(getline(file,line)){
        raw.push_back(line);
    }
    cout<<"Part 1: ";
    part1(raw);
    cout<<"Part 2: ";
    part2(raw);
}

void part1(vector<string> inp){
    vector<vector<int>> mp;
    for(int i = 0;i<inp[0].size()-1;i++){
        mp.push_back(vector<int>(26));
    }
    for(auto& line: inp){
        for(int i = 0;i<line.size()-1;i++){
            mp[i][line[i]-'a']++;
        }
    }
    string msg = "";
    int mx;
    for(auto& v: mp){
        mx = -1;
        for(auto& val: v){
            mx = max(val, mx);
        }
        for(int i = 0;i<26;i++){
            if(v[i] == mx){
                msg+=i+'a';
                break;
            }
        }
    }
    cout<<msg<<endl;
}

void part2(vector<string> inp) {
    vector<vector<int>> mp;
    for (int i = 0; i < inp[0].size() - 1; i++) {
        mp.push_back(vector<int>(26));
    }
    for (auto& line : inp) {
        for (int i = 0; i < line.size() - 1; i++) {
            mp[i][line[i] - 'a']++;
        }
    }
    string msg = "";
    int mn;
    for (auto& v : mp) {
        mn = 9999;
        for (auto& val : v) {
            if(val<mn && val != 0){
                mn = val;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (v[i] == mn) {
                msg += i + 'a';
                break;
            }
        }
    }
    cout << msg << endl;
}