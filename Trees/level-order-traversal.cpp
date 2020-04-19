void levelOrderSearch(Node *root){
    if(root==nullptr)
        return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *current = q.front();
        q.pop();
        cout<<current->data;
        if(current->left != nullptr)
            q.push(current->left);
        if(current->right != nullptr)
                q.push(current->right);
    }
}