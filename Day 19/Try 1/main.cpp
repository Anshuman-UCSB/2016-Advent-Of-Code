#include <iostream>
#include <vector>

using namespace std;

int main(){
    int inp = 3017957;
    string trash;
    vector<int> elves(inp, 1);
    // elves[0] = 0;
    int ind = 0;
    int next;
    while(true){
        for(next = (ind+1)%inp;elves[next] == 0;next = (next+1)%inp){}
        if(ind == next){
            break;
        }
        elves[ind] += elves[next];
        elves[next] = 0;
        // cout<<"Elf "<<ind+1<<" stole from "<<next+1<<endl;
        ind = next;
        // cin>>trash;
        for(next = (ind+1)%inp;elves[next] == 0;next = (next+1)%inp){}
        ind = next;
    }
    cout<<"The final elf is "<<ind+1<<endl;

}