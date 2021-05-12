//REVERSE THE LIST USING ITERATION
void reverse(){
    struct node *current,*next,*prev;
    current=head;
    prev=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

//REVERSE THE LIST USING RECURSION
void reverse(struct node* p){
    if(p==NULL){
        return;
    }
    reverse(p->next);
    printf("%d ",p->data);
}

