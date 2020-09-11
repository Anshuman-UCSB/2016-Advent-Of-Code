#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

struct word{
    vector<char> v;
    word(){};  
    word(string inp){
        for(auto c:inp)
            v.push_back(c);
    }

    void swapPos(int a, int b){
        swap(v[a],v[b]);
    }

    void swapLetter(char a, char b){
        int x, y;
        for(int i = 0;i<v.size();i++){
            if(v[i] == a)
                x = i;
            if(v[i] == b)
                y = i;
        }
        swap(v[x],v[y]);
    }

    void rotateRight(int x){
        vector<char> t(v);
        int rotateInd;
        for(int i = 0;i<t.size();i++){
            rotateInd = (i-x);
            while(rotateInd < 0)
                rotateInd+=t.size();
            t[i] = v[rotateInd];
        }
        v = t;
    }

    void rotateLeft(int x){
        vector<char> t(v);
        for(int i = 0;i<t.size();i++){
            t[i] = v[(i+x)%t.size()];
        }
        v = t;
    }

    void rotateLetter(char l){
        int ind;
        for(int i = 0;i<v.size();i++){
            if(v[i] == l){
                ind = i;
                break;
            }
        }
        int rotate = 1;
        if(ind >= 4){
            rotate++;
        }
        rotate+=ind;

        rotateRight(rotate);
    }

    void reverse(int a, int b){
        stack<char> s;
        for(int i = a;i<=b;i++){
            s.push(v[i]);
        }
        for(int i = a;i<=b;i++){
            v[i] = s.top();
            s.pop();
        }
    }

    void move(int a, int b){
        char dat = v[a];
        v.erase(v.begin() + a);
        v.insert(v.begin()+b, dat);
    }

    string toString(){
        string build = "";
        for(auto c: v){
            build+=c;
        }
        return build;
    }

};

void example(word& w){
    cout<<w.toString()<<endl;
    w.swapPos(4,0);
    cout<<w.toString()<<endl;
    w.swapLetter('d','b');
    cout<<w.toString()<<endl;
    w.reverse(0,4);
    cout<<w.toString()<<endl;
    w.rotateLeft(1);
    cout<<w.toString()<<endl;
    w.move(1,4);
    cout<<w.toString()<<endl;
    w.move(3,0);
    cout<<w.toString()<<endl;
    w.rotateLetter('b');
    cout<<w.toString()<<endl;
    w.rotateLetter('d');
    cout<<w.toString()<<endl;

}

int main(){
    fstream file("input");
    string line;
    string s1, s2;
    char c1, c2;
    int i1, i2;
    word w("abcdefgh");
    while(getline(file, line)){
        stringstream ss(line);
        ss>>s1;
        if(s1 == "move"){
            ss>>s1>>i1>>s2>>s2>>i2;
            // cout<<"moving "<<i1<<" to "<<i2<<endl;
            w.move(i1, i2);
        }else if(s1 == "rotate"){
            ss>>s1;
            if(s1 == "right"){
                ss>>i1;
                w.rotateRight(i1);
            }else if(s1 == "left"){
                ss>>i1;
                w.rotateLeft(i1);
            }else{
                ss>>s1>>s1>>s1>>s1>>c1;
                w.rotateLetter(c1);
            }
        }else if(s1 == "swap"){
            ss>>s1;
            if(s1 == "letter"){
                ss>>c1>>s1>>s2>>c2;
                w.swapLetter(c1, c2);
            }else{
                ss>>i1>>s1>>s2>>i2;
                w.swapPos(i1, i2);
            }
        }else if(s1 == "reverse"){
            ss>>s1>>i1>>s2>>i2;
            w.reverse(i1, i2);
        }else{
            cout<<"UH OH "<<line<<endl;
            exit(1);
        }
        cout<<w.toString()<<endl;
    }
}
