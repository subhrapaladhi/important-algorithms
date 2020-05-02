#include<bits/stdc++.h>
using namespace std;

class node{
    private:
    int data;
    
    public:
    node *left, *right;
    node(int);
    int showData();
    void editData(int);
};

node:: node(int data = 0){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

int node:: showData(){
    return this->data;
}

void node::editData(int data){
    this->data = data;
}

node* insertNode(int, node*);
node* searchNode(int, node*);
void inorderTraversal(node*);
node* deleteNode(int, node*);

int main(){
    node *root = insertNode(5, NULL);
    insertNode(2, root);
    insertNode(4, root);
    insertNode(7, root);
    insertNode(6, root);
    insertNode(1, root);
    insertNode(3, root);
    
    inorderTraversal(root);
    cout<<endl;
    deleteNode(2, root);
    inorderTraversal(root);
    return 0;
}

node* insertNode(int data, node *root){
    if(!root)  // first node
        return new node(data);

    if(data <= root->showData())
        root->left = insertNode(data, root->left);
    else
        root->right = insertNode(data, root->right);

    return root;
}


node* searchNode(int data, node *root){
    if(!root)
        cout<<"node with such data not present"<<endl;

    else{
        if(data == root->showData())
            cout<<"node found"<<endl;

        else if(data < root->showData())
            searchNode(data, root->left);
        else
            searchNode(data, root->right);
    }

    return root;
}

node* deleteNode(int data, node *root){
    if(!root){
        cout<<"node not found"<<endl;
        return root;
    }

    else if(data < root->showData())
        root->left = deleteNode(data, root->left);

    else if(data > root->showData())
        root->right = deleteNode(data, root->right);
    
    else{   // data = root->data;
        if(!root->left){     //root->left = NULL
            node *temp = root->right;
            delete root;
            return temp;
        }

        else if(!root->right){  //root->right = NULL
            node *temp = root->left;
            delete root;
            return temp;
        }

        else{               // both child present
            node* succParent = root;
            node* succ = root->right;
            while(succ->left){
                succParent = succ;
                succ = succ->left;
            }
            if(succParent == root)     // when root->right->left = NULL
                succParent->right = succ->right;

            else
                succParent->left = succ->right;

            root->editData(succ->showData());
            delete succ;

            return root;
        }
    }
    return root;
}

void inorderTraversal(node *root){
    if(!root)
        return;
    
    inorderTraversal(root->left);
    cout<<root->showData()<<endl;
    inorderTraversal(root->right);
}