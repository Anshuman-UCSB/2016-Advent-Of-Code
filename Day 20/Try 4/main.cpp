#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

#define range pair<unsigned int, unsigned int>

range parse(string& line){
    unsigned int a, b;
    char c;
    stringstream ss(line);
    ss>>a>>c>>b;
    return make_pair(a,b);
}

int main(){
    fstream file("input");
    string line;
    vector<range> m;
    while(getline(file, line))
        m.push_back(parse(line));
    
    bool unsorted = true;
    while(unsorted){
        unsorted = false;
        for(int i = 0;i<m.size()-1;i++){
            if(m[i].first > m[i+1].first){
                // cout<<"Swapping "<<m[i].first<<" and "<<m[i+1].first<<endl;
                swap(m[i], m[i+1]);
                unsorted = true;
            }
        }
    }
    for(int i = 0;i<m.size()-1;i++){
        if(m[i].second>=m[i+1].first){
            cout<<"merging "<<m[i].first<<", "<<m[i].second << " and "<<m[i+1].first<<", "<<m[i+1].second <<endl;
            m[i].second = m[i+1].second;
            m.erase(m.begin()+i+1);
            i--;
        }
    }
    
    unsigned int total = UINT32_MAX;
    for(auto& p: m){
        cout<<p.first<<", "<<p.second<<endl;
        total -= p.second - p.first + 1;
        cout<<total<<endl;
    }
    cout<<total<<endl;
    //806069261 too high
    //806069260 too high
    //806069261
    
}