#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;

        node(int data){
            this->data = data;
            this->next = nullptr;        
        }
};



node* reverse(node*);

int main(){
    // node *head 
    // create a linked list 
    // reverse(head);
    return 0;
}


node* reverse(node *head){
    // when we reach the last node, then head->next so, we return and newhead = head(last node)
    if(head==nullptr || head->next == nullptr)
        return head;
    
    // newHead will be passed to each prev. recursive call to reverse() so finnaly returning the reversed ll head to main()
    node *newHead = reverse(head->next);
    // reversing the next node's pointer towards itself
    head->next->next = head;
    // making current node's pointer to null
    head->next = nullptr;
    // returning the reversed ll head node
    return newHead;
}
