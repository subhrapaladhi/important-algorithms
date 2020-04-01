#include<bits/stdc++.h>
using namespace std;

class node{
    private:
        int data;
        node *left, *right;
    public:
        
        node(int data=0){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

        node* insert(node*, int);
        void search(node*, int);
        void inorderTraversal(node*);
};

int main(){
    node *root=NULL, bst;
    root = bst.insert(root,5);
    bst.insert(root,2);
    bst.insert(root,4);
    bst.insert(root,7);
    bst.insert(root,6);
    bst.insert(root,1);
    bst.insert(root,3);

    // bst.inorderTraversal(root);
    int searchTerm;
    cin>>searchTerm;
    bst.search(root, searchTerm);
    return 0;
}

node* node::insert(node* root, int data){
    // cout<<"root = "<<root<<endl;
    if(!root){          // first node creation
        root = new node(data);
    }
    else{
        if(data <= root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    }
    return root;
}

void node::inorderTraversal(node *root){
    if(!root)
        return;
    
    inorderTraversal(root->left);
    cout<<"data = "<<root->data<<endl;
    inorderTraversal(root->right);
}

void node::search(node *root, int searchTerm){
    if(root == NULL)
        cout<<"not found"<<endl;
    else if(root->data == searchTerm)
        cout<<"found"<<endl;
    else if(root->data < searchTerm)
        search(root->right, searchTerm);
    else if(root->data > searchTerm)
        search(root->left, searchTerm);
}