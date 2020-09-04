#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    fstream file("input");
    string line;
    vector<int> regs = {0, 0, 1, 0};
    vector<string> raw;
    while(getline(file,line)){
        raw.push_back(line);
    }

    for(int i = 0;i<raw.size();){
        stringstream ss(raw[i]);
        int temp;
        // cout<<ss.str()<<endl;
        ss>>line;
        if(line=="cpy"){
            ss>>line;
            try{
                temp = stoi(line);
            }catch(...){
                temp = regs[line[0]-'a'];
            }
            ss>>line;
            regs[line[0]-'a'] = temp;
                i++;
        }else if(line == "inc"){
            ss>>line;
            regs[line[0]-'a']++;
            i++;            
        }else if(line == "dec"){
            ss>>line;
            regs[line[0]-'a']--;
            i++;
        }else{
            ss>>line;
            try{
                temp = stoi(line);
            }catch(...){
                temp = regs[line[0]-'a'];
            }
            if(temp){
                ss>>line;
                i+=stoi(line);
            }else{
                i++;
            }
        }
            
    }

    for(int i = 0;i<4;i++){
        cout<<char('a'+i)<<": "<<regs[i]<<endl;
    }
}