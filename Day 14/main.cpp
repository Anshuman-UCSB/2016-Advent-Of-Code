#include <iostream>
#include <vector>
#include <utility>
#include "md5.h"
using namespace std;



int main(){
    string input = "abc";
    int ind = 0;
    vector<int> keyIndexes;
    vector<pair<char, int>> candidates;
    while(keyIndexes.size() < 64){
        string hash = md5(input+to_string(ind));
        cout<<ind<<" - "<<hash<<endl;
        for(int i = 0;i<hash.size()-2;i++){
            if(i + 4 < hash.size()){
                char c = hash[i];
                for(int j =1;j<=4;j++){
                    if(c != hash[i+j]){
                        goto threes;
                    }
                }
                for(auto& p: candidates){
                    if(p.first == c && p.second >= ind){
                        
                        keyIndexes.push_back(p.second-1000);
                        cout<<"    Match found! "<<p.second-1000<<" was matched."<<endl;
                        break;
                    }
                }
            }
            threes:;
            if(hash[i] == hash[i+1] && hash[i+1] == hash[i+2]){
                candidates.push_back(make_pair(hash[i], ind+1000));
                cout<<"  New candidate for key, "<<candidates.back().first<<" checking through "<<candidates.back().second<<endl;
            }
        }

        ind++;
    }
    sort(keyIndexes.begin(), keyIndexes.end());
    cout<<endl;
    for(int i = 0;i<keyIndexes.size();i++){
        cout<<i<<": "<<keyIndexes[i]<<endl;
    }
}