#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
        int count;
        bool endofword;
        map<string,trieNode*> children;

        trieNode(){
            this->count=0;
            this->endofword=false;
        }

        void insertNode(string,trieNode*);
        bool searchString(string,trieNode*);
        int count_prefix(string,trieNode*);
        bool deleteNode(string,trieNode*);
};

void trieNode::insertNode(string data, trieNode *root){

    trieNode *current = root;
    int i,j;
    for(i=0; i<data.length(); i++){
        string key = string(1,data[i]);
        trieNode *node = current->children[key];
        if(!node){
            node = new trieNode();
            current->children[key] = node;
        }   
        current = node;
        current->count++;
    }

    current->endofword = true;
}

bool trieNode::searchString(string data, trieNode *root){
    trieNode *current = root;
    
    for(int i=0; i<data.length(); i++){
        string key = string(1,data[i]);
        trieNode *node = current->children[key];
        if(!node) {
            return false;
        }
        current = node;
    }

    return true;
}

int trieNode::count_prefix(string data, trieNode *root){
    trieNode *current = root;

    for(int i=0; i<data.length(); i++){
        string key = string(1,data[i]);
        trieNode *node = current->children[key];
        cout<<key<<" = kye :: node = "<<node<<endl;
        if(!node){
            return 0;
        }
        current = node;
    }

    return current->count;
}

bool trieNode::deleteNode(string data, trieNode *root){
    stack<trieNode*> stk;

    trieNode *current = root;
    
    for(int i=0; i<data.length(); i++){
        string key = string(1,data[i]);
        trieNode *node = current->children[key];
        cout<<"key "<<key<<" "<<node<<endl;
        if(!node){
            cout<<"false "<<key<<endl;
            return false;
        }
        current = node;
        stk.push(node);
        cout<<"top: "<<stk.top()<<endl;
    }

    while(!stk.empty()){
        current = stk.top();
        cout<<current<<endl;
        stk.pop();
        current->count--;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    trieNode *root = new trieNode();

    // inserting
    int n,q;
    cin>>n;
    string s;
    while(n--){
        cin>>q;
        cin>>s;
        
        if(q==1){
            // insert
            root->insertNode(s,root);
            cout<<"insert completed"<<endl;
        }

        else if(q==2){
            // search
            bool ispresent = root->searchString(s,root);
            cout<<"the string is present in the trie: "<<ispresent<<endl;
        }

        else if(q==3){
            // count occurence
            int count = root->count_prefix(s,root);
            cout<<"the number of occurences in the trie: "<<count<<endl;
        }

        else if(q==4){
            // delete
            bool isdelete = root->deleteNode(s,root);

            if(isdelete){
                cout<<"the string is deleted from the trie "<<isdelete<<endl;
            } else {
                cout<<"the string NOT deleted from the trie "<<isdelete<<endl;
            }
            
        }
    }

    return 0;
}