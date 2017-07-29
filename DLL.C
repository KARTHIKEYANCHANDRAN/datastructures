#include<stdio.h>
#include<conio.h>
struct node
{
  int data;
  struct node * prev;
  struct node * next;
};
int searchnode(struct node * head,int data,struct node **prev)
{
  struct node *temp=NULL;
  *prev=NULL;
  temp=head;
  while(temp!=NULL&&data>temp->data)
  {
   *prev=temp;
   temp=temp->next;
  }
  if(temp==NULL)
    return 0;
  else if(temp->data==data)
    return 1;
  else
    return 0;
}
int insertnode(struct node **head,int data,struct node **tail)
{
  struct node *prev=NULL;
  struct node *newnode=NULL;
  if(searchnode(*head,data,&prev))
  {
   printf("duplicate insertion!\n");
   return 0;
  }
  newnode=(struct node*)malloc(sizeof(struct node));
  if(!newnode)
    return 0;
  newnode->data=data;
  if(prev==NULL)
  {
   newnode->prev=NULL;
   newnode->next=*head;
   if(*head)
   {
     (*head)->prev=newnode;
   }
   else
      *tail=newnode;
  *head=newnode;
  }
  else
  {
   newnode->prev=prev;
   newnode->next=prev->next;
   prev->next=newnode;
   if(newnode->next)
   {
     newnode->next->prev=newnode;
   }
  }
  return 1;
}
int traverselist(struct node *head)
{
  struct node *temp=NULL;
  temp=head;
  if(!temp)
    return 0;
  while(temp)
  {
    printf("%d->",temp->data);
    temp=temp->next;
  }
  return 1;
}
int deletenode(struct node **head,int data,struct node **tail)
{
  struct node *prev=NULL;
  struct node *temp=NULL;
  if(!searchnode(*head,data,&prev))
  {
   return 0;
  }
  if(prev==NULL)
  {
   temp=*head;
   *head=(*head)->next;
   if(!(*head))
      *tail=NULL;
   else
      (*head)->prev=NULL;
  }
  else
  {
   temp=prev->next;
   prev->next=temp->next;
   if(!(temp->next))
      *tail=prev;
   else
      temp->next->prev=prev;
  }
  free(temp);
  return 1;
}
int main()
{
  struct node *head=NULL;
  struct node *prev=NULL;
  struct node *tail=NULL;
  int n,i,data;
  clrscr();
  printf("enter no of digits to be inserted\n");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    printf("enter no %d:",i);
    scanf("%d",&data);
    insertnode(&head,data,&tail);
  }
  traverselist(head);
  printf("enter no to be deleted\n");
  scanf("%d",&data);
  deletenode(&head,data,&tail);
  traverselist(head);
  printf("enter no to be searched\n");
  scanf("%d",&data);
  if(searchnode(head,data,&prev))
      printf("found\n");
  if(!searchnode(head,data,&prev))
      printf("not found");
  getch();
  return 0;
}
