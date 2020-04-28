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

void inorder(Node*);
void swapSubTreesOfLevel(Node*, int);

int main(){
    int n;
    cin>>n;
    
    Node *root = new Node(1);
    
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    
    int level = 1, a, b;
    
    while(n>0 && !q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp==nullptr){
            if(!q.empty())
                q.push(nullptr);
            level++;
        } else {
            cin>>a>>b;
            if(a!=-1){
                temp->left = new Node(a);
                q.push(temp->left);
            }
            if(b!=-1){
                temp->right = new Node(b);
                q.push(temp->right);
            }
            n--;
        }
    }

    int t, k, itr, lvl;
    cin>>t;
    for(int i=0; i<t; ++i){
        cin>>k;
        itr = 2;
        lvl = k;
        while(lvl<=level){
            swapSubTreesOfLevel(root, lvl);
            lvl = itr*k;
            itr++;
        }
        inorder(root);
        cout<<endl;
    }

    return 0;
}

void swapSubTreesOfLevel(Node *root, int k){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    int level = 1;

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp==nullptr){
            if(!q.empty())
                q.push(nullptr);
            level++;
        } else {
            if(level == k){
                Node *sw = temp->left;
                temp->left = temp->right;
                temp->right = sw;
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void inorder(Node *root){
    if(root==nullptr)
        return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}