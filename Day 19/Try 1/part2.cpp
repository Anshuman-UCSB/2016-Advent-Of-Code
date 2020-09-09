#include <iostream>
#include <vector>


using namespace std;

struct Node{
    int id;
    Node* next;
    Node* back;
    Node(){};
    Node(int dat, Node* n, Node* b): id(dat), next(n), back(b) {};

    void del(){
        back->next = next;
        next->back = back;
        delete this;
    }
};

void insert(Node* head, int dat){
    Node* t = new Node(dat, head, head->next);
    head->next->back = t;
    head->next = t;
}

int main(){
    int inp = 3017957;
    Node* head = new Node(1,0,0);
    Node* tail = head;
    for(int i = 2;i<=inp;i++){
        Node* t = new Node(i, 0, tail);
        tail->next = t;
        tail = t;
    }
    tail->next = head;
    head->back = tail;
    int size = inp;
    // for(Node* p = head; p; p = p->next){
    //     cout<<p->id<<endl;
    // }
    Node* p = head;
    Node* t;
    while(size > 1){
        t = p;
        for(int i = 0;i<size/2;i++){t = t->next;}
        if(size%1000 == 0)
            cout<<t->id<<" got stolen "<<size<<" remain. "<<endl;
        t->del();
        p = p->next;
        size--;
    }
    cout<<p->id<<" is the survivor."<<endl;
}