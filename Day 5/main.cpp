#include <fstream>
#include <iostream>
#include <vector>

#include "md5.h"
using namespace std;

void part1();
void part2();

int main() {
    part2();
}

void part1(){
    string id = "ffykfhsq";
    string password = "";
    int num = 0;
    string hash;
    // cout<<md5("abc3231929")<<endl;
    while(password.size()<8){
        // cout<<(id+to_string(num++))<<endl;
        hash = md5(id+to_string(num));
        if(hash.substr(0, 5) == "00000"){
            password+=hash[5];
            cout<<(id+to_string(num))<<endl;
        }
        num++;
    }
    cout<<password<<endl;
}

void part2() {
    string id = "ffykfhsq";
    string password = "________";
    int num = 0;
    string hash;
    // cout<<md5("abc3231929")<<endl;
    while (password.find("_") != string::npos) {
        // cout<<(id+to_string(num++))<<endl;
        hash = md5(id + to_string(num));
        if (hash.substr(0, 5) == "00000") {
            if(hash[5]<'8' && hash[5]>='0'){
                cout << (id + to_string(num)) << " - ";
                cout<< hash<<endl;
                if(password[hash[5]-'0'] == '_')
                    password[hash[5]-'0'] = hash[6];
                    cout<<password<<endl;
            }
        }
        num++;
    }
    cout << password << endl;
}