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
  int n, i, x;
  printf ("How many numbers: ");
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      printf ("Enter number %d: ", i);
      scanf ("%d", &x);
      insert (x);
      print ();
    }
}
