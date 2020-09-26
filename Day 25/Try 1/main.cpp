#include <vector>
#include <iostream>
using namespace std;

vector<int> solve(int inp){
    vector<int> out;
    int a(inp), b(0), c(0), d(0);
    d = a;
    c = 11;
    b = 231;
    d+=b*c;
    jump3:;
    a = d;
    jump2:;
    b = a;
    a = 0;
    c = 2;
    jump1:;
    if(b == 0){
        goto jump4;
    }
    b--;
    c--;
    if(c){
        goto jump1; 
    }
    a++;
    goto jump1;
    jump4:;
    b = 2;
    while(true){
        if(!c){
            break;
        }
        b--;
        c--;
    }
    cout<<b<<endl;
    out.push_back(b);
    if(a){
        goto jump2;
    }
    goto jump3;
}

int main(){
    solve(0);
}