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
        Node* pNew = new Node;
        if(iA->exp > iB->exp){
            pNew->exp = iA->exp;
            pNew->coe = iA->coe;
            iA = iA->next;
        }else if (iA->exp < iB->exp){
            pNew->exp = iB->exp;
            pNew->coe = iB->coe;
            iB = iB->next;
        }else{
            pNew->coe = iB->coe+iA->coe;
            if(pNew->coe == 0) {
                delete pNew;
                continue;
            }
            pNew->exp = iA->exp;
            iA=iA->next;
            iB=iB->next;
        }
        pNew->next = nullptr;
        pNow->next = pNew;
        pNow = pNow->next;
    }

    if(iA!=nullptr){
        pNow->next = iA;
    }

    if(iB!=nullptr){
        pNow->next = iB;
    }

    return pRes;
}

int main(){
    Node* pA = readPol();
    Node* pB = readPol();
    Node* pC = polAdd(pA,pB);

    int len = 0;
    Node *t = pC->next;
    while(t!=nullptr){
        t=t->next;
        len++;
    }

    cout<<len;
    t = pC->next;
    while(t!=nullptr){
        cout<<" "<<t->exp<<" "<<t->coe;
    }
    cout<<endl;
}