#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

struct State{
    vector<vector<string>> floors;
    int elev;
    int steps;
    State(){
        steps = 0;
        elev = 0;
        for(int i = 0;i<4;i++){
            floors.push_back(vector<string>());
        }
    }

    State(const State& old){
        this->steps = old.steps + 1;
        elev = old.elev;
        for(int i = 0;i<4;i++){
            floors.push_back(vector<string>());
            floors[i] = old.floors[i];
        }
    }

    string toStr(){
        stringstream ss;
        ss<<elev<<"|";
        for(int i = 0;i<4;i++){
            ss<<i;
            for(auto& e: floors[i]){
                ss<<e;
            }
        }
        return ss.str();
    }
};

bool isValidFloor(vector<string>& flr){
    bool volatileChip = false;
    bool gen = false;
    for(auto& s: flr){
        if(s[1]=='G'){
            gen = true;
        }
    }
    for(auto& s: flr){
        
        if(s[1]=='C'){
            // cout<<"testing chip "<<s<<endl;
            bool paired = false;
            for(auto& c: flr){
                if(c[0] == s[0] && c[1] == 'G'){
                    // cout<<"Chip "<<s<<" is paired with "<<c<<endl;
                    paired = true;
                    break;
                }
            }
            if(!paired){
                if(gen){
                    return false;
                }
            }
        }
    }
    return true;
        

}

bool isValid(State& inp){
    for(auto& floor: inp.floors){
        if(isValidFloor(floor) == false){
            return false;
        }
    }
    return true;
}

vector<State> variations(State inp){
    vector<State> out;
    int floorNum = inp.elev;
    
    //move item up
    if(floorNum != 3){ //if not on top floor
        for(int i = 0;i<inp.floors[floorNum].size();i++){
            State temp(inp);
            temp.elev++;
            temp.floors[floorNum+1].push_back(temp.floors[floorNum][i]);
            temp.floors[floorNum].erase(temp.floors[floorNum].begin + i);
            if(isValid(temp)){
                out.push_back(temp);
            }
        }
    }
}

int main(){
    State start;
    start.floors[0].push_back("HC");
    start.floors[0].push_back("LC");
    start.floors[1].push_back("HG");
    start.floors[2].push_back("LG");
    cout<<start.toStr()<<endl;
    cout<<isValid(start)<<endl;

    //an unpaired chip cannot be with a generator
    
}