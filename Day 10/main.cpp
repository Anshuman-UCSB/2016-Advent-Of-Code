#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include <utility>
using namespace std;

void giveBot(map<int, pair<int, int>>& m, int bot, int low, int high, map<int, pair<int, int>>& instr);

void giveValue(map<int, pair<int, int>>& m, int bot, int dat, map<int, pair<int, int>>& instr) {
    if(m[bot].first == 0 || m[bot].second == 0){
        cout<<"Giving value "<<dat<<" to bot "<<bot<<endl;
        if(m[bot].first == 0)
            m[bot].first = dat;
        else
            m[bot].second = dat;
        if(m[bot].first != 0 && m[bot].second != 0){
            cout<<"Bot "<<bot<<" is full, following instructions."<<endl;
            giveBot(m, bot, instr[bot].first, instr[bot].second, instr);
        }
    }
    else{
        cout<<"Gave data to full bot..."<<endl;
        exit(1);
    }

}

void giveBot(map<int, pair<int, int>>& m, int bot, int low, int high, map<int, pair<int, int> > &instr) {
    if(m[bot].first == 0 || m[bot].second == 0){
        return;
    }
    int lVal = min(m[bot].first,m[bot].second);
    int hVal = max(m[bot].first, m[bot].second);
    m[bot].first = m[bot].second = 0;

    giveValue(m, low, lVal, instr);
    giveValue(m, high, hVal, instr);
    cout << "Gave low (" << lVal << ") to bot " << low << endl;
    cout << "Gave high (" << hVal << ") to bot " << high << endl;
}

int main() {
    fstream file("input");
    string line;
    stringstream ss;
    int a, b, c;
    vector<string> raw;
    while (getline(file, line)){
        raw.push_back(line);
    }

    map<int, pair<int, int>> m;
    map<int, pair<int, int>> data;

    for(auto& l: raw){
        if(l[0] == 'b'){
            ss = stringstream(l);
            ss >> line;
            ss >> line;
            a = stoi(line);
            for( int i = 0;i<5;i++)
                ss >> line;
            b = stoi(line);
            for (int i = 0; i < 5; i++)
                ss>>line;
            c = stoi(line);
            cout<<a<<" -> "<<b<<", "<<c<<endl;
            m[a] = make_pair(b,c);
        }
        else{
            ss = stringstream(l);
            ss>>line>>line;
            a = stoi(line);
            ss>>line>>line>>line>>line;
            b = stoi(line);
            giveValue(data, b, a, m);
        }
    }

}