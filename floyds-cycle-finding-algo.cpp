node* findCycle(node *head){
    node *fast = head, *slow = head;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
            return 1;       // cycle detected
    }
    return 0;               // no cycle
}