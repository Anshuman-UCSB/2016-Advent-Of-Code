#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    fstream file("input");
    string line;
    unsigned int len = UINT32_MAX;
    vector<bool> map(len, true);
    // cout<<"hit"<<endl;
    // for(unsigned int i = 0;i<len;i++){
    //     map[i] = true;
    // }
    unsigned int a, b;
    char c;
    while(getline(file, line)){
        stringstream ss(line);
        ss>>a>>c>>b;
        cout<<"Working on range "<<a<<" -> "<<b<<endl;
        for(unsigned int i = a; i<=b;i++){
            // if(rand()%1000 == 1)
            //     cout<<i<<endl;
            map[i] = false;
        }
        cout<<"Finished range "<<a<<" -> "<<b<<endl;
    }
    unsigned int out = 0;
    for(auto c: map){
        out+=c;
    }
    cout<<"Answer: "<<out<<endl;
}