#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    int part1 = 0;

    fstream file("input");
    string line;
    vector<vector<int>> triangles;
    string temp;
    while(getline(file, line)){
        stringstream ss(line);
        vector<int> t;
        ss >> temp;
        t.push_back(stoi(temp));
        ss >> temp;
        t.push_back(stoi(temp));
        ss >> temp;
        t.push_back(stoi(temp));
        triangles.push_back(t);
    }
    int sum, mx;
    for(auto& v: triangles){
        sum = 0;
        mx = -1;
        for(auto& p: v){
            mx = max(mx, p);
            sum += p;
            cout<<p<<" ";
        }cout<<endl;
        sum-=mx;
        if(mx<sum){
            part1++;
        }
    }  
    cout<<part1<<endl;
    
    vector<vector<int>> trip2;

    for(int i = 0;i<triangles.size();i+=3){
        trip2.push_back(vector<int>{triangles[i][0], triangles[i + 1][0], triangles[i + 2][0]});
        trip2.push_back(vector<int>{triangles[i][1], triangles[i+1][1], triangles[i+2][1]});
        trip2.push_back(vector<int>{triangles[i][2], triangles[i + 1][2], triangles[i + 2][2]});
    }
    int part2 = 0;
    for (auto &v : trip2)
    {
        sum = 0;
        mx = -1;
        for (auto &p : v)
        {
            mx = max(mx, p);
            sum += p;
            cout << p << " ";
        }
        cout << endl;
        sum -= mx;
        if (mx < sum)
        {
            part2++;
        }
    }
    cout << part2 << endl;
}
