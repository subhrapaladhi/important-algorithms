/*
@ root is considered as level 0
*/

int height(Node *root){
    if(root->left==nullptr && root->right==nullptr)
        return 0;

    int leftHeight = root->left!=nullptr? height(root->left)+1 : 0;
    int rightHeight = root->right!=nullptr? height(root->right)+1 : 0;

    if(leftHeight>rightHeight)
        return leftHeight;
    return rightHeight;
}