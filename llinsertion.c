#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head;
void
insertatbeginning (int x)
{
  struct node *temp = (struct node *) malloc (sizeof (struct node));
  temp->data = x;
  temp->next = head;
  head = temp;
}
void insertatend (int data)
{
  struct node *temp1 = (struct node *) malloc (sizeof (struct node *));
  temp1->data = data;
  temp1->next = NULL;
  if(head==NULL){
      head=temp1;
      return;
  }
  struct node* temp2 = head;
  while(temp2->next!=NULL){
      temp2=temp2->next;
  }
  temp2->next=temp1;
  return;
}
void insertatmiddle (int data,int n){
  struct node *temp1 = (struct node *) malloc (sizeof (struct node *));
  temp1->data = data;
  temp1->next = NULL;
  if(n==1){
    temp1->next=head;
    head=temp1;
    return;
  }
  struct node* temp2 = head;
  for(int i=0;i<n-2;i++){
    temp2=temp2->next;
  }
  temp1->next=temp2->next;
  temp2->next=temp1;
}
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

void
print ()
{
  struct node *temp = head;
  printf ("List is ");
  while (temp != NULL)
    {
      printf ("%d ", temp->data);
      temp = temp->next;
    }
  printf ("\n");
}

int
main ()
{
  head = NULL;
  int n,ch,ib,ie,im_data,im_pos;
  while(1){
  printf("1.INSERT AT BEGINNING\n");
  printf("2.INSERT AT END\n");
  printf("3.INSERT AT MIDDLE\n");
  printf("4.DELETE AT ANY POSITION");
  printf("Enter the operation: ");
  scanf("%d",&n);
  switch(n){
    case 1: printf("Enter the numbers to insert: ");
            scanf("%d",&n);
            for(int i=1;i<=n;i++){
              printf("Enter number %d: ",i);
              scanf("%d",&ib);
              insertatbeginning(ib);
            }
            print();
            break;
    case 2: printf("Enter the numbers to insert: ");
            scanf("%d",&n);
            for(int i=1;i<=n;i++){
              printf("Enter number %d: ",i);
              scanf("%d",&ie);
              insertatend(ie);
            }
            print();
            break;
    case 3: printf("Enter the numbers to insert: ");
            scanf("%d",&n);
            for(int i=1;i<=n;i++){
              printf("Enter number %d: ",i);
              scanf("%d",&im_data);
              printf("Enter number %d position: ",i);
              scanf("%d",&im_pos);
              insertatmiddle(im_data,im_pos);
            }
            print();
            break;
    case 4: printf("Enter the position to delete: ");
            scanf("%d",&dp);
            deleteatanypos(dp);
            print();
    default:printf("Invalid Operation");
    }
    printf("Do you want to continue (Y/N): ");
    scanf("%c",&ch);
    if(ch=='Y') continue;
    else exit(0);
  }
}
