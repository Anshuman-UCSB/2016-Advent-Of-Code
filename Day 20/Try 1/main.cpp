#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

struct Rule{
    int low;
    int high;
    Rule(){}
    Rule(int l, int h):low(l), high(h){};
    bool isInvalid(int inp){
        return inp>=low && inp<=high;
    }
};

int main(){
    fstream file("input");
    string line;
    vector<Rule> rules;
    string a, b;
    while(getline(file, line)){
        a = b = "";
        int i = 0;
        for(;line[i] != '-';i++){
            a+=line[i];
        }
        i++;
        b = line.substr(i);
        // cout<<a<<", "<<b<<endl;

        rules.push_back(Rule(stoul(a), stoul(b)));
    }
    bool valid = true;
    unsigned int i = 0;
    int p2 = 0;
    while(i <= 4294967295){
        if(rand() % 10000 == 0)
            cout<<"i - "<<i<<endl;
        valid = true;
        for(auto& r: rules){
            if(r.isInvalid(i)){
                valid = false;
                // cout<<i<<" failed on rule "<<r.low<<" - "<<r.high<<endl;
                i = r.high+1;
                break;
            }
        }
        if(valid){
            // cout<<"Valid ip: "<<i<<endl;
            i++;
            p2++;
            // break;
        }
    }
    cout<<"Part 2: "<<p2<<endl;
}