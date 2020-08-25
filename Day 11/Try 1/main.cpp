#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
#define floor vector<string>

class wrapper{
    public:
    int pos;
    vector<floor> f;
    wrapper(){
        pos = 0;
        for(int i = 0;i<4;i++)
            f.push_back(floor());
        
    }

    void print(){
        cout<<"F4 ";
        string temp = "";
        for(auto& s: f[3]){
            cout<<temp<<s;
            temp = ", ";
        }cout<<endl;
        cout<<"F3 ";
        temp = "";
        for(auto& s: f[2]){
            cout<<temp<<s;
            temp = ", ";
        }cout<<endl;
        cout<<"F2 ";
        temp = "";
        for(auto& s: f[1]){
            cout<<temp<<s;
            temp = ", ";
        }cout<<endl;
        cout<<"F1 ";
        temp = "";
        for(auto& s: f[0]){
            cout<<temp<<s;
            temp = ", ";
        }cout<<endl;
    }

    void parse() {
        //Example
        f[0].push_back("HM");
        f[0].push_back("LM");

        f[1].push_back("HG");

        f[2].push_back("LG");
    }

    string hash(){
        stringstream out;
        string t = "";
        out<<"<"<<pos<<"_F1:";
        for(auto& c: f[0]){
            out<<t<<c;
            t = ",";
        }
        t = "";
        out<<"_F2:";
        for(auto& c: f[1]){
            out<<t<<c;
            t = ",";
        }
        t = "";
        out<<"_F3:";
        for(auto& c: f[2]){
            out<<t<<c;
            t = ",";
        }
        t = "";
        out<<"_F4:";
        for(auto& c: f[3]){
            out<<t<<c;
            t = ",";
        }
        out<<">";
        return out.str();
    }

    bool isStable(){
        for(floor& fl: f){
            
        }
    }
};

int main(){
    wrapper wr;
    wr.parse();
    wr.print();
    cout<<wr.hash()<<endl;
}