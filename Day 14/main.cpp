#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "md5.h"
using namespace std;

string part2Hash(string inp){
    string temp = inp;
    for(int i = 0;i<2017;i++){
        temp = md5(temp);
        // cout<<temp<<endl;
    }
    return temp;
}

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

void generateHashes(int num){
    ofstream file;
    file.open("hashes.txt");
    string base = "ngcjuoqr";
    for(int i = 0;i<num;i++){
        file<<part2Hash(base+to_string(i))<<endl;
    }
}

int main(){
    string base = "ngcjuoqr";
    generateHashes(100000);
    exit(1);
    int ind = 0;
    vector<int> keys;
    while(keys.size() < 64){
        string hash = part2Hash(base+to_string(ind));
        char trp = hasTriple(hash);
        if(trp != 'z'){
            for(int i = 1;i<1000;i++){
                if(hasPenta(part2Hash(base+to_string(ind+i))) == trp){
                    cout<<keys.size()<<" : "<<ind<<" is a valid key."<<endl;
                    keys.push_back(ind);
                    break;
                }
            }
        }
        ind++;
    }
}