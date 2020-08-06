#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

void part1();
void part2();

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

bool isSSL(string ip){
    queue<string> q;
    vector<string> blocks;
    string build = "";
    for(int i = 0;i<ip.size();i++){
        if(ip[i] == '[' || ip[i] == ']'){
            blocks.push_back(build);
            build = "";
        }else{
            build += ip[i];
        }
    }
    blocks.push_back(build);

    for(int i = 0;i<blocks.size();i+=2){
        // cout<<"current block: "<<blocks[i]<<endl;
        for(int j = 0;j<blocks[i].size()-2;j++){
            // cout<<"    current block index: "<<j<<endl;
            if(blocks[i][j] == blocks[i][j+2] && blocks[i][j+1] != blocks[i][j]){
                q.push(blocks[i].substr(j,3));
                // cout<<"    ABA: "<<q.back()<<endl;
            }
        }
    }
    string bab;
    while(q.empty() == false){
        bab = q.front();
        q.pop();
        bab[0] = bab[1];
        bab[1] = bab[2];
        bab[2] = bab[0];
        for(int i = 1;i<blocks.size();i+=2){
            for (int j = 0; j < blocks[i].size() - 2; j++) {
                // cout<<blocks[i].substr(j,3)<<endl;
                if (blocks[i].substr(j,3) == bab) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isABBA(string ip){
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
    part2();
}

void part1(){
    vector<string> raw = read();
    int tls = 0;
    bool valid;
    string build;
    bool inner;
    for(string& ip: raw){
        cout<< ip<<endl;
        if(isABBA(ip)){
            tls++;
        }
    }
    cout<<tls<<endl;
}
//not 108, 69

void part2(){
    int ans = 0;
    for(string ip: read()){
        if(isSSL(ip)){
            ans++;
        }
    }
    cout<<ans<<endl;
    // cout << isSSL("dnwtsgywerfamfv[gwrhdujbiacaowtcirq]bjbhmuxdcacsenlctwgh") << endl;
}