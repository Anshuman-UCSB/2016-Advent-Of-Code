#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main(){
    fstream file("input");
    string line;
    getline(file,line);
    vector<long> weights(line.size(), 1);
    // cout<<line<<endl;
    // for(auto& c: weights){
    //     cout<<c;
    // }cout<<endl;

    long long size = 0;

    bool compressed = false;
    string temp;
    for(int i = 0;i<line.size();i++){
        if(line[i] == '('){
            compressed = true;
            temp = "";
            for(i++;line[i]!='x';i++){
                temp+=line[i];
            }
            int a = stoi(temp);
            temp = "";
            for (i++; line[i] != ')'; i++) {
                temp += line[i];
            }
            int b = stoi(temp);
            // cout<<"a: "<<a<<", b: "<<b<<endl;
            for(int j = i;j<=i+a;j++){
                weights[j]*=b;
            }
            // for (auto& c : weights) {
            //     cout << c;
            // }
            // cout << endl;
            compressed = false;
        }else{
            size+=weights[i];
        }
    }
    cout<<size<<endl;

}