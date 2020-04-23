#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int freq;
        string data;
        Node *left, *right;

        Node(int freq = 0, string data = ""){
            this->data = data;
            this->freq = freq;
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node* createHuffmanTree(vector<Node*>);
void decode(Node*, string);
void inorderTraversal(Node*);

int main(){
    // a-4  b-3  c-1  d-5
    auto newNode = [](string data, int freq){return new Node(freq,data);};

    vector<Node*> leaves;
    // sorted according to frequencies
    leaves.push_back(newNode("c", 1));
    leaves.push_back(newNode("b", 3));
    leaves.push_back(newNode("a", 4));   
    leaves.push_back(newNode("d", 5));

    Node *root = createHuffmanTree(leaves);

    inorderTraversal(root);

    return 0;
}

Node* createHuffmanTree(vector<Node*> leaves){
    while(leaves.size()>1){
        if(leaves[0]->freq<leaves[2]->freq){
            Node *newNode = new Node(leaves[0]->freq+leaves[1]->freq);
            newNode->left = leaves[0];
            newNode->right = leaves[1];
            leaves.erase(leaves.begin());
            leaves.erase(leaves.begin());
            leaves.push_back(newNode);
        }
    }

    return leaves[0];
}

void decode(Node *root, string s){
    Node *p = root;

    for(int i=0; i<s.length(); i++){
        p = s[i] == '0' ? p->left : p->right;
        if(p->left == nullptr && p->right == nullptr){
            cout<<p->data;
            p = root;
        }
    }
}

void inorderTraversal(Node *root){
    if(root==nullptr)
        return ;
    inorderTraversal(root->left);
    cout<<root->freq<<endl;
    inorderTraversal(root->right);
}