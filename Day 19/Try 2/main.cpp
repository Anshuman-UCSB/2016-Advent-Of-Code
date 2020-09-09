#include <vector>
#include <iostream>
using namespace std;

int main(){
    int inp = 3017957;
    vector<int> m;
    int ind, temp;
    for(int inp = 1;inp<1000;inp++){
        // inp = 9;
        ind = 0;
        m.clear();
        for(int i = 1;i<=inp;i++){
            m.push_back(i);
        }

        while(m.size()>1){
            temp = ind + m.size()/2;
            temp %= m.size();
            // cout<<"elf "<<m[ind]<<" stole from "<<m[temp]<<endl;
            // for(auto& c: m){
            //     cout<<c<<' ';
            // }cout<<endl;
            m.erase(m.begin()+temp);
            // if(temp>=ind){
            if(ind>=m.size() || temp <ind){
                ind--;
            }
            ind = (ind+1)%m.size();
            // }
        }
        cout<<inp<<", "<<m[0]<<endl;
    }
}