#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#define range pair<unsigned int, unsigned int>

using namespace std;

bool overlapping(range& a, range& b){
    if((a.first >= b.first && a.first <= b.second) ||
       (b.first >= a.first && b.first <= a.second) ||
       (a.second >= b.first && a.second <= b.second) ||
       (b.second >= a.first && b.second <= a.second) ){
           return true;
    }
    return false;
}

void combine(range& a, range& b){
    a.first = min(a.first, b.first);
    a.second = max(a.second, b.second);
}

int main(){
    fstream file("input");
    string line;
    vector<range> m;
    string a, b;
    bool overlapped;
    range t;
    while(getline(file,line)){
        a = line.substr(0, line.find('-'));
        b = line.substr(line.find('-')+1);
        t = make_pair(stoul(a), stoul(b));
        overlapped = false;
        for(auto& p: m){
            if(overlapping(p, t)){
                overlapped = true;
                cout<<"Combining pairs "<<p.first<<", "<<p.second<<" with "<<t.first<<", "<<t.second<<endl;
                combine(p, t);
                cout<<"Created "<<p.first<<", "<<p.second<<endl;
            }
        }
        if(!overlapped){
            cout<<"pair "<<t.first<<", "<<t.second<<" was added to the vector."<<endl;
            m.push_back(t);
        }
    }

    cout<<UINT32_MAX<<endl;
    unsigned int total = UINT32_MAX;
    for(auto& p: m){
        total-= p.second-p.first+1;
        cout<<"Range of size: "<<p.second-p.first+1<<endl;
        cout<<"Total choices: "<<total<<endl<<endl;
    }
    //399174020 Too high
    //399174303
    //2546657668
}