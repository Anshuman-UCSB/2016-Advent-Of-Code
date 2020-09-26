#include <iostream>
#include <vector>
using namespace std;

bool isClock(int inp){
    int num = 0;
    bool expected = false;
    string delim = " ";
    int a(inp), b(0), c(0), d(0);
    d = a;
    c = 11;
    b = 231;
    bigLoop2:;
    d+=b*c;

    a = d;
    bigLoop1:;
    b = a;
    a = 0;
    while(true){
        c = 2;
        loop1:;
        if(b == 0){
            goto exitLoop;
        }
        b--;
        c--;
        if(c)
            goto loop1;
        a++;
    }
    exitLoop:;

    b = 2;
    b-=c;
    
    // cout<<b<<delim;
    delim = delim == " "?"\n":" ";

    if(b != expected)
        return false;
    expected = !expected;
    
    if(a)
        goto bigLoop1;
    if(num < 10000)
        goto bigLoop2;
    //After 10k tries
    return true;
}

int main(){
    int i;
    for(i = 0;!isClock(i);i++){
        if(rand()%10000 == 69){
            cout<<i<<" - "<<isClock(i)<<endl;
        }
    }
    cout<<i<<" - "<<isClock(i)<<endl;
}