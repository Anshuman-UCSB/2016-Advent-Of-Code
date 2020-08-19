#include <vector>
using namespace std;

class Bot{
    public:
    int id;
    bool isBot;
    vector<int> data;
    Bot(int id, bool bot){
        this->id = id;
        isBot = bot;
    }
    
    void addData(int val);
    void give(Bot &b1, Bot &b2);
    void act()
}