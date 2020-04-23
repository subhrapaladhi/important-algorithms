#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

        Node(int data=0){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }       
};

int main(){

    int n;
    cin>>n;
    queue<Node*> q;
    
    auto newNode = [](int data){return new Node(data);};

    int temp1, temp2;

    Node* root = newNode(1);
    q.push(root);
    for(int i=0; i<n; i++){
        cin>>temp1>>temp2;
        
    }

    return 0;
}
