#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;

void toggleInstruction(string& instr){
    //inc, dec, cpy, tgl, jnz
    switch(instr[0]){
        case 'i':
            instr = "dec" + instr.substr(3);
            return;
        case 'd':
            instr = "inc" + instr.substr(3);
            return;
        case 't':
            instr = "inc" + instr.substr(3);
            return;
        case 'c':
            instr = "jnz" + instr.substr(3);
            return;
        case 'j':
            instr = "cpy" + instr.substr(3);
            return;
    }
}

struct Computer{
    map<char, int> regs;
    vector<string> instructions;
    int ind;
    Computer(){
        ind = 0;
        regs.clear();
        instructions.clear();
        regs['a'] = 0;
        regs['b'] = 0;
        regs['c'] = 0;
        regs['d'] = 0;
    }

    string toString(){
        stringstream ss("");
        ss<<"["<<regs['a']<<", "<<regs['b']<<", "<<regs['c']<<", "<<regs['c']<<"]";
        return ss.str();
    }

    void readInstructions(){
        ind = 0;
        fstream file("input");
        string line;
        instructions.clear();
        while(getline(file, line)){
            if(line.back() == '\r')
                line.pop_back();
            instructions.push_back(line);
        }
    }

    void act(){
        string instr = instructions[ind];
        stringstream ss(instr);
        string temp;
        ss>>temp;

        if(temp == "inc"){
            ss>>temp;
            if(temp[0]>='a' && temp[0]<='d'){
                char c = temp[0];
                incr(c);
            }
        }else if(temp == "dec"){
            ss>>temp;
            decr(temp[0]);
        }else if(temp == "cpy"){
            string a, b;
            ss>>a>>b;
            cpy(a,b);
        }else if(temp == "jnz"){
            string a, b;
            ss>>a>>b;
            jnz(a,b);
        }else if(temp == "tgl"){
            string a;
            ss>>a;
            tgl(a);
        }
    }

    void cpy(string a, string b){
        if(b[0] >= 'a' && b[0] <= 'd'){
            if(a[0] >= 'a' && a[0] <= 'd'){
                regs[b[0]] = regs[a[0]];
            }else{
                regs[b[0]] = stoi(a);
            }
        }
        ind++;
    }

    void jnz(string a, string b){
        if(a[0] >= 'a' && a[0] <= 'd'){
            if(b[0] >= 'a' && b[0] <= 'd'){
                if(regs[a[0]]){
                    ind+=regs[b[0]];
                }else{
                    ind++;
                }
            }else{
                if(regs[a[0]]){
                    ind+=stoi(b);
                }else{
                    ind++;
                }
            }
        }else{
            if(b[0] >= 'a' && b[0] <= 'd'){
                if(stoi(a)){
                    ind+=regs[b[0]];
                }
                else{
                    ind++;
                }
            }else{
                if(stoi(a)){
                    ind+=stoi(b);
                }else{
                    ind++;
                }
            }
        }
    }

    void tgl(string a){
        int dInd;
        if(a[0] >= 'a' && a[0] <= 'd'){
            dInd = regs[a[0]];
        }else{
            dInd = stoi(a);
        }
        if(ind+dInd >= 0 && ind+dInd < instructions.size())
            toggleInstruction(instructions[ind+dInd]);
        ind++;
    }

    void cpy(int a, char b){
        regs[b] = a;
        ind++;
    }

    void cpy(char a, char b){
        regs[b] = regs[a];
        ind++;
    }

    void incr(char a){
        if(a>='a' && a<='d'){
            regs[a]++;
        }
        ind++;
    }

    void decr(char a){
        regs[a]--;
        ind++;
    }

    void jnz(char a, char b){
        if(regs[a]){
            ind+=regs[b];
        }else{
            ind++;
        }
    }

    void jnz(int a, char b){
        if(a){
            ind+=regs[b];
        }else{
            ind++;
        }
    }

    void jnz(int a, int b){
        if(a){
            ind+=b;
        }else{
            ind++;
        }
    }

};

int main(){
    Computer c;
    c.regs['a'] = 12;
    c.readInstructions();
    cout<<c.toString()<<endl;
    for(auto& l:c.instructions){
        cout<<l<<endl;
    }
    while(c.ind < c.instructions.size()){
        string instr = c.instructions[c.ind];
        // cout<<" > "<<" - "<<c.instructions[c.ind];
        c.act();
        if(rand() % 100000 == 1)
            cout<<"("<<c.ind<<") "<<instr<<" > "<<c.toString()<<endl;
    }
    cout<<c.toString()<<endl;

}