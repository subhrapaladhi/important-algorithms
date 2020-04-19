node* reverse(node *head){
    // when we reach the last node, then head->next so, we return and newhead = head(last node)
    if(head==NULL || head->next == NULL)
        return head;
    
    // newHead will be passed to each prev. recursive call to reverse() so finnaly returning the reversed ll head to main()
    node *newHead = reverse(head->next);
    // reversing the next node's pointer towards itself
    head->next->next = head;
    // making current node's pointer to null
    head->next = NULL;
    // returning the reversed ll head node
    return newHead;
}


