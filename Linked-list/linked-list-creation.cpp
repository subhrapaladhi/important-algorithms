#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data=0){
        this->data = data;
        this->next = nullptr;
    }
};

Node* addNode(Node*, int);
void printLL(Node*);

int main(){
    Node *head = nullptr;

    head = addNode(head,1);
    addNode(head,2);
    addNode(head,3);
    addNode(head,4);
    addNode(head,5);

    // printLL(head);
    return 0;
}

Node* addNode(Node* head, int data){
    Node *newNode = new Node(data), *p = head;
    if(head == nullptr)
        return newNode;

    while(p->next != nullptr)
        p = p->next;

    p->next = newNode;
    return head;    
}

void printLL(Node *head){
    Node *p = head;

    while(p!=nullptr){
        cout<<p->data<<endl;
        p = p->next;
    }
}