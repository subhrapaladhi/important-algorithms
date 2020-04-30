// algorithm to check if a given tree is BST

/*
  @parameters
    - root : root of the tree
  @return value
    - BST? true:false;
*/


vector<int> data;

void convert(Node *root){
    if(root==nullptr)
        return;
    convert(root->left);
    data.push_back(root->data);
    convert(root->right);
}

bool checkBST(Node *root){
    convert(root);

    for(auto i=data.begin()+1; i<data.end(); i++){
        if(*(i-1)>=*i)
            return false;
    }
    return true;
}