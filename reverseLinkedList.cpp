#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;

        node(int data){
            this->data = data;
            this->next = NULL;        
        }
};

node* reverse(node*);
void addNode(node*, int);

int main(){
    node *head=NULL; 
    // create a linked list 
    addNode(head, 4);
    cout<<"head = "<<head->data;
    addNode(head, 7);
    addNode(head, 1);
    addNode(head, 9);
    addNode(head, 3);
    // reverse(head);
    return 0;
}

node* reverse(node *head){
    // when we reach the last node, then head->next so, we return and newhead = head(last node)
    if(head==NULL || head->next == NULL)
        return head;
    
    // newHead will be passed to each prev. recursive call to reverse() so finnaly returning the reversed ll head to main()
    node *newHead = reverse(head->next);
    // reversing the next node's pointer towards itself
    head->next->next = head;
    // making current node's pointer to null
    head->next = NULL;
    // returning the reversed ll head node
    return newHead;
}

void addNode(node *head, int data){
    node *p = head, *newNode = new node(data);
    cout<<newNode->data;
    if(p == NULL){
        head = newNode;
    }
    else{
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = newNode;
    }
}