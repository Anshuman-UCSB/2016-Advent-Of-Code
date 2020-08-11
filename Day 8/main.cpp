#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

void part1();
void part2();

int main(){
    part1();   
}

void rect(vector<vector< int>>& m, int a, int b){
    for(int i = 0;i<a;i++){
        for(int j = 0;j<b;j++){
            m[j][i] = 1;
        }
    }
}

void rotateColOne(vector<vector< int>>& m, int a){
    for(int i = m.size()-1;i>0;i--){
        swap(m[i][a],m[i-1][a]);
    }
}

void rotateCol(vector<vector<int>>& m, int a, int b){
    for(int i = 0;i<b;i++){
        rotateColOne(m, a);
    }
}

void rotateRowOne(vector<vector<int>>& m, int a) {
    for (int i = m[a].size() - 1; i > 0; i--) {
        swap(m[a][i], m[a][i - 1]);
    }
}

void rotateRow(vector<vector<int>>& m, int a, int b) {
    for (int i = 0; i < b; i++) {
        rotateRowOne(m, a);
    }
}

void print(vector<vector<int>>& m) {
    for (auto& c : m) {
        for (auto& l : c) {
            if(l){
                cout<<"#";
            }else{
                cout<<' ';
            }
        }
        cout << endl;
    }
}

void part1(){
    vector<vector<int>> m;
    for(int i = 0;i<6;i++){
        m.push_back(vector<int>(50, 0));
    }
    fstream file("input");
    string line, temp;
    stringstream ss;
    while(getline(file,line)){
        ss = stringstream(line);
        ss>>line;
        if(line == "rect"){
            ss>>line;
            int a,b;
            temp = "";
            for(auto& c: line){
                if(c == 'x'){
                    a = stoi(temp);
                    temp = "";
                }else{
                    temp+=c;
                }
            }
            b = stoi(temp);
            cout<<"Making rect at "<<a<<", "<<b<<endl;
            rect(m, a, b);
        } else if(line == "rotate"){
            ss>>line;
            if(line == "row"){
                ss>>line;
                int a = stoi(line.substr(2));
                ss>>line;
                ss>>line;
                int b = stoi(line);
                cout<<"Rotating row on "<<a<<", "<<b<<endl;
                rotateRow(m, a, b);
            }else{
                ss >> line;
                int a = stoi(line.substr(2));
                ss >> line;
                ss >> line;
                int b = stoi(line);
                cout << "Rotating col on " << a << ", " << b << endl;
                rotateCol(m, a, b);
            }
        }
    }
    int sum = 0;
    for(int i = 0;i<m.size();i++){
        for(int j = 0;j<m[i].size();j++){
            sum+=m[i][j];
        }
    }
    cout<<"Part 1: "<<sum<<endl;
    print(m);
}