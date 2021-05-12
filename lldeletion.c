//DELETE THE NUMBER AT ANY POSITION
void deleteatanypos(int n){
    struct node* temp = head;
    if(n==1){
        head = temp->next;
        free(temp);
        return;
    }
    int i;
    for(i=0;i<n-2;i++){
        temp=temp->next;
    }
    struct node* temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
}

