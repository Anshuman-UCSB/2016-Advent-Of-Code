#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dragonCurve(vector<int>& v){
    v.push_back(0);
    for(int i = v.size()-2;i>=0;i--)
        v.push_back(!v[i]);
}

void trim(vector<int>& v, int size){
    while(v.size()>size)
        v.pop_back();
}

vector<int> checkSum(vector<int>& inp){
    if(inp.size()%2 == 0){
        vector<int> out;
        for(int i = 0;i<inp.size()-1;i+=2){
            out.push_back(inp[i] == inp[i+1]);
        }
        return checkSum(out);
    }
    return inp;
}

int main(){
    int size = 35651584;
    vector<int> test = {0,1,1,1,1,0,1,0,1,1,0,0,1,0,0,1,1};
    while(test.size()<=size){
        dragonCurve(test);
    }
    trim(test, size);
    test = checkSum(test);
    for(auto& c: test){
        cout<<c;
    }cout<<endl;
}