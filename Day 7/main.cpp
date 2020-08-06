#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void part1();

vector<string> read(){
    vector<string> out;
    fstream file("input");
    string line;
    while(getline(file,line)){
        out.push_back(line);
    }
    return out;
}

bool isTls(string inp){
    for(int i = 0;i<inp.size()-3;i++){
        if(inp[i] == inp[i+3] && inp[i+1] == inp[i+2] && inp[i] != inp[i+1]){
            return true;
        }
    }
    return false;
}

bool abbaIp(string ip){
    bool inner = false;
    bool valid = false;
    string build = "";
    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] == '[') {
            if (isTls(build)) {
                valid = true;
            }
            build = "";
            inner = true;
        } else if (ip[i] == ']') {
            if (isTls(build)) {
                return false;
            }
            build = "";
            inner = false;
        } else {
            build += ip[i];
        }
    }
    if(isTls(build)){
        valid = true;
    }
    return valid;
}


int main(){
    part1();
}

void part1(){
    vector<string> raw = read();
    int tls = 0;
    bool valid;
    string build;
    bool inner;
    for(string& ip: raw){
        cout<< ip<<endl;
        if(abbaIp(ip)){
            tls++;
        }
    }
    cout<<tls<<endl;
}
//not 108, 69