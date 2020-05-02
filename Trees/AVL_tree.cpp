#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data, height;
        Node *left, *right;

        Node(int);
};

Node:: Node(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 0;
}

int getheight(Node *r){
    if(r==nullptr)
        return -1;
    return r->height;
}

Node* rightRotation(Node *root){
    Node *x = root->left;
    Node *xr = x->right;
    
    x->right = root;
    root->left = xr;

    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return x;
}

Node* leftRotation(Node *root){
    Node *x = root->right;
    Node *xl = x->left;

    x->left = root;
    root->right = xl;

    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return x;
}

Node* insertNode(Node *root, int data){
    if(root==nullptr)
        return new Node(data);

    if(data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    
    int balancefactor = getheight(root->left) - getheight(root->right);

    if(balancefactor >1 && data < root->left->data) // left left case
        return rightRotation(root);

    if(balancefactor > 1 && data > root->left->data){ // left right case
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    if(balancefactor < -1 && data > root->right->data)  // right right case
        return leftRotation(root);
    
    if(balancefactor < -1 && data < root->right->data){  // right left case
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void inorder(Node *root){
    if(root==nullptr)
        return ;

    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

void preorder(Node *root){
    if(root==nullptr)
        return ;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node *root;

	root = insertNode(root, 20); 
    root = insertNode(root, 10); 
	root = insertNode(root, 30); 
	root = insertNode(root, 40); 
	root = insertNode(root, 50); 
	root = insertNode(root, 25); 

    inorder(root);
    cout<<endl<<endl; 
    preorder(root);

    return 0;
}