#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
    
        Node(int data = 0){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node* addNode(Node*, int);
void inOrderTraversal(Node*);

void levelOrderSearch(Node *root){
    if(root==nullptr)
        return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *current = q.front();
        q.pop();
        cout<<current->data<<endl;
        if(current->left != nullptr)
            q.push(current->left);
        if(current->right != nullptr)
                q.push(current->right);
    }
}

int main(){
    Node *root = nullptr;
    root = addNode(root, 5);
    addNode(root, 3);
    addNode(root, 2);
    addNode(root, 1);
    addNode(root, 4);
    addNode(root, 6);
    addNode(root, 8);
    addNode(root, 7);
    addNode(root, 9);

    inOrderTraversal(root);
    cout<<endl<<endl;
    levelOrderSearch(root);
    return 0;
}

Node* addNode(Node *root, int data){
    Node *newNode = new Node(data), *p = root;

    if(root == nullptr)
        return newNode;
    
    if(data<=root->data){
        root->left = addNode(root->left, data);
    }
    else{
        root->right = addNode(root->right, data);
    }

    return root;
}


void inOrderTraversal(Node *root){
    if(root == nullptr)
        return ;
    
    inOrderTraversal(root->left);
    cout<<root->data<<endl;
    inOrderTraversal(root->right);
}