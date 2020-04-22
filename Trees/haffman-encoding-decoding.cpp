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