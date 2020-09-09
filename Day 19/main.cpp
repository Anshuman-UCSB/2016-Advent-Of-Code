#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int inp = 3017957;
    int p = 1;
    while(3*p < inp){
        p*=3;
    }
    if(p == inp){
        cout<< p<<endl;;
    }
    cout<< inp-p+max(inp-2*p, 0)<<endl;
}

// int main(){
//     int inp = 3017957;
//     int winner = 1;
//     for(int i = 4;i<=inp;i++){
//         // cout<<pow(i-1,1./3)<<endl;
//         // cout<<pow(i-1, 1./3) <<endl;
//         if(log(i-1)/log(3) - int(log(i-1)/log(3)) == 0){
//             // cout<<i<<endl;
//             winner = 1;
//         }else{
//             winner++;
//             if(winner*2>i){
//                 winner++;
//             }
//         }
//         // cout<<"("<<i<<", "<<winner<<")"<<endl;
        
//     }
//     cout<<inp<<" - "<<winner<<endl;
// }
//4441591 too high