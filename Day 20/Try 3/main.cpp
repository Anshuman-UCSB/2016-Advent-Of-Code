#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    vector<bool> m(UINT32_MAX, true);
    fstream file("input");
    string line;
    unsigned int a, b;
    char trash;
    while(getline(file,line)){
        stringstream ss(line);
        ss>>a>>trash>>b;
        cout<<a<<" - "<<b<<endl;
        for(unsigned int i = a;i<=b;i++){
            if(rand() % 1000000 == 0){
                cout<<i<<endl;
            }
            m[i] = false;
        }
    }

    unsigned int out = 0;
    for(auto b: m){
        out+=b;
    }
    cout<<"Part 2: "<<out<<endl;
}