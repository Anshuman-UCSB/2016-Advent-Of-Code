#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <fstream>
#include "md5.h"
using namespace std;



char hasTriple(string inp){
    for(int i =0;i<inp.size()-2;i++){
        if(inp[i] == inp[i+1] && inp[i+1] == inp[i+2]){
            return inp[i];
        }
    }
    return 'z';
}

char hasPenta(string inp){
    for(int i =0;i<inp.size()-4;i++){
        if(inp[i] == inp[i+1] && inp[i] == inp[i+2]&& inp[i] == inp[i+3]&& inp[i] == inp[i+4]){
            return inp[i];
        }
    }
    return 'z';
}


int main(){
    fstream file("hashes.txt");
    string line;
    vector<string> raw;
    while(getline(file,line)){
        raw.push_back(line);
    }
    string base = "ngcjuoqr";
    int ind = 0;
    vector<int> keys;
    while(keys.size() < 64){
        string hash = raw[ind];
        char trp = hasTriple(hash);
        if(trp != 'z'){
            for(int i = 1;i<1000;i++){
                if(hasPenta(raw[ind+i]) == trp){
                    cout<<keys.size()<<" : "<<ind<<" is a valid key."<<endl;
                    keys.push_back(ind);
                    break;
                }
            }
        }
        ind++;
    }
}