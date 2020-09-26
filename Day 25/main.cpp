#include <iostream>

using namespace std;

bool solve(int inp){
    int a(inp), b(0), c(0), d(0);
    int step = 0;
    bool wrong = true;
    
    d = a;
    c = 11;
    b = 231;
    d+=b*c;
    while(step++<1000){
        a = d;
        do{
            b = a;
            a = 0;
            while(true){
                c = 2;
                do{
                    if(b == 0){
                        goto out;
                    }
                    b--;
                    c--;
                }while(c);
                a++;
            }
            out:;
            b = 2;
            while(true){
                if(c== 0){
                    break;
                }
                b--;
                c--;
            }
            // cout<<b<<endl;
            if(b == wrong){
                return false;
            }
            wrong = !wrong;
        }while(a);
    }
    return true;
}

int main(){
    int ans= 0;
    while(!solve(++ans)){}
    cout<<"Answer: "<<ans<<endl;
}