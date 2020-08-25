#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> read(){
    fstream file("input");
    string line;
    vector<string> out;
    while(getline(file,line)){
        out.push_back(line);
    }
    return out;
}

int main(){
    int regs[4] = {0, 0, 0, 0};
    vector<string> raw = read();

    for(int i = 0;i<raw.size();i++){
        stringstream ss(raw[i]);
        int val;
        string temp, a, b;
        ss>>temp;
        switch(temp[0]){
            case 'i':
                ss>>a;
                regs[a[0]-'a']++;
                // cout<<"Incrementing "<<a[0]<<endl;
                break;
            case 'd':
                ss>>a;
                regs[a[0]-'a']--;
                // cout<<"Decrementing "<<a[0]<<endl;
                break;
            case 'c':
                ss>>a>>b;
                if(a[0]>='a' && a[0]<='d'){
                    val = regs[a[0]-'a'];
                }else{
                    val = stoi(a);
                }
                // cout<<"Copying "<<val<<" to "<<b[0]<<endl;
                regs[b[0]-'a'] = val;
                break;
            case 'j':
                ss>>a>>b;
                if(a[0]>='a' || a[0]<='d'){
                    val = regs[a[0]-'a'];
                }else{
                    val = stoi(a);
                }
                if(val){
                    // cout<<"Jumping "<<stoi(b)<<endl;
                    i+=stoi(b);
                }else{
                    // cout<<"Not jumping"<<endl;
                }

                break;
        }
    }
    for(auto& r: regs){
        cout<<r<<" ";
    }cout<<endl;
}