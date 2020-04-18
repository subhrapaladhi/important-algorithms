node* findMergePoint(node *head1, node *head2){
    node *p1=head1, *p2=head2;

    while(p1!=p2){
        if(p1->next == nullptr)
            p1 = head2;
        else
            p1 = p1->next;
        if(p2->next == nullptr)
            p2 = head1;
        else
            p2 = p2->next;
    }

    return p1;
}