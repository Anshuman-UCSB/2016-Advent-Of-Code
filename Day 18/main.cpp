#include <vector>
#include <iostream>
#define row vector<char>

using namespace std;

bool isTrap(char a, char b, char c){
    int sum = 0;
    if(a == '^')
        sum++;
    if(b == '^')
        sum++;
    if(c == '^')
        sum++;

    if(sum == 2 && b == '^')
        return true;
    if(sum == 1 && b != '^')
        return true;
    return false;
}

row makeRow(row& r){
    row out = {' '};
    for(int i = 1;i<r.size()-1;i++){
        if(isTrap(r[i-1],r[i],r[i+1])){
            out.push_back('^');
        }else{
            out.push_back('.');
        }
    }
    out.push_back(' ');
    return out;
}

void printRow(row& r){
    for(auto& c: r){
        cout<<c;
    }cout<<endl;
}

int main(){
    string inp = "^.^^^.^..^....^^....^^^^.^^.^...^^.^.^^.^^.^^..^.^...^.^..^.^^.^..^.....^^^.^.^^^..^^...^^^...^...^.";
    int rows = 400000;
    
    row start = {' '};
    for(auto& c: inp){
        start.push_back(c);
    }
    start.push_back(' ');
    row t = start;
    int safe = 0;
    for(int i = 0;i<rows;i++){

        for(auto& c: t){
            if(c == '.'){
                safe++;
            }
        }
        // printRow(t);
        t = makeRow(t);
    }
    cout<<"Part 1: "<<safe<<endl;

}