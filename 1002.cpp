#include<iostream>

using namespace std;

struct Node{
    float coe;
    int exp;
    struct Node* next;
};

Node* readPol(){
    Node* pHead = new Node;
    pHead->coe=0;
    pHead->exp=0;
    pHead->next=nullptr;

    int len;
    cin>>len;
    if(len==0) return pHead;

    int c,e;
    Node* pNow = pHead;
    while(len>0){
        cin>>e>>c;
        Node* t = new Node;
        t->coe=c;
        t->exp=e;
        t->next=nullptr;

        pNow->next=t;
        pNow=pNow->next;
        len--;
    }

    return pHead; 
}

Node* polAdd(Node* pA, Node* pB){
    Node* pRes=new Node;
    Node* pNow=pRes;

    Node* iA=pA->next;
    Node* iB=pB->next;

    while(iA!=nullptr&&iB!=nullptr){
        Node* pNew
        if(iA->exp>iB->exp){

        }
    }
}

int main(){
    Node* pA = readPol();
    Node* pB = readPol();
    Node* pC = polAdd(pA,pB);
}