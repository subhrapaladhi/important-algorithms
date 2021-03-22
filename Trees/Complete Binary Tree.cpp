#include<bits/stdc++.h>
using namespace std;
 
class Node{
    public:
    
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }

    static Node* insert(Node *root, int data){
        if(!root) return new Node(data);

        queue<Node*> level;
        level.push(root);
        Node *temp, *target;
        int n;
        while(!level.empty()){
            int n = level.size();
            while(n--){
                temp = level.front();
                level.pop();

                if(temp->left){
                    level.push(temp->left);
                } else {
                    temp->left = new Node(data);
                    return root;
                }

                if(temp->right){
                    level.push(temp->right);
                } else {
                    temp->right = new Node(data);
                    return root;
                }
            }
        }

        return root;
    }

    static void inorder(Node *root){
        if(!root) return;

        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }

    static void levelorder(Node *root){
        if(!root) return;
        queue<Node*> level;
        level.push(root);
        int n, l=0;
        Node *temp;

        while(!level.empty()){
            int n = level.size();
            cout<<endl<<"Level "<<l++<<endl;
            while(n--){
                temp = level.front();
                level.pop();
                cout<<temp->data<<"  ";
                if(temp->left) level.push(temp->left);
                if(temp->right) level.push(temp->right);
            } 

        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr = {4,1,6,2,3,6,23,7,9};
    
    Node *root = Node::insert(NULL,arr[0]);
    
    for(int i=1; i<arr.size(); i++){
        root->insert(root, arr[i]);
    }
    Node::inorder(root);
    Node::levelorder(root);

    return 0;
}