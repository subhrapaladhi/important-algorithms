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
        node* search(node*, int);
        node* deleteNode(node*, int);
        node* minNode(node*);
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
    cout<<"enter search term: ";
    cin>>searchTerm;
    bst.inorderTraversal(root);
    cout<<endl;
    node *pos = bst.deleteNode(root, searchTerm);
    bst.inorderTraversal(pos);
    // node *pos = bst.search(root, searchTerm);
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

node* node::search(node *root, int searchTerm){
    if(root==NULL or root->data == searchTerm)
        return root;
    else if(root->data < searchTerm)
        search(root->right, searchTerm);
    else if(root->data > searchTerm)
        search(root->left, searchTerm);
}

node* node::deleteNode(node *root, int searchTerm){
    if(root==NULL)
        return root;
    else if(root->data < searchTerm)
        root->right = deleteNode(root->right, searchTerm);
    else if(root->data > searchTerm)
        root->left = deleteNode(root->left, searchTerm);
    else{
        if(root->left == NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }

        else{
            node *succParent = root;
            node *succ = root->right;
            while(succ->left!=NULL){
                succParent = succ;
                succ = succ->left;
            }

            // for the first time succ->left != NULL therefore succParent!=root;
            if(succParent != root)
                succParent->left = succ->right;
            // for the first time succ->left == NULL therefore succParent==root;
            else
                succParent->right = succ->right;
            root->data = succ->data;
            delete succ;
            return root;
        }
    }
    return root;
}