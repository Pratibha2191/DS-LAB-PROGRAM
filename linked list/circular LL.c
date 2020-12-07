#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
 {
  int info;
  struct node *link;
 };
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
 {
  printf("mem full\n");
  exit(0);
 }
 return x;
}
void freenode(NODE x)
{
free(x);
}
NODE cir_insert_front(NODE last,int item)
{
NODE temp;
temp=getnode();
temp->info=item;
if(last==NULL)
 last=temp;
temp->link=last->link;
last->link=temp;
return last;
}
NODE cir_insert_rear(NODE last,int item)
{
NODE temp;
temp=getnode();
temp->info=item;
if(last==NULL)
last=temp;
else
temp->link=last->link;
last->link=temp;
return temp;
}
NODE cir_delete_front(NODE last)
{
NODE temp,first;
if(last==NULL)
{
printf("list empty\n");
return NULL;
}
if(last->link==last)
{
printf("item deleted is  %d\n",last->info);
freenode(last);
return NULL;
}
first=last->link;
last->link=first->link;
printf("item deleted at front end is %d\n",first->info);
freenode(first);
return last;
}
NODE cir_delete_rear(NODE last)
{
NODE prev;
if(last==NULL)
{
printf("list empty\n");
return NULL;
}
if(last->link==last)
{
printf("item deleted is %d\n",last->info);
freenode(last);
return NULL;
}
prev=last->link;
while(prev->link!=last)
{
prev=prev->link;
}
prev->link=last->link;
printf("Item deleted at rear end: %d\n",last->info);
freenode(last);
return prev;
}
void display(NODE last)
{
NODE temp;
if(last==NULL)
{
 printf("list empty\n");
 return;
}
printf("Contents of circular list are: ");
for(temp=last->link;temp!=last;temp=temp->link)
{
printf("%d  ",temp->info);
}
printf("%d\n",temp->info);
}
void main()
{
int item,choice;
NODE last=NULL;
for(;;)
{
printf("\n1:cir_insert_front  2:cir_insert_rear  3:cir_delete_front  4:cir_delete_rear  5:display  6:exit\n");
printf("Enter the choice: ");
scanf("%d",&choice);
switch(choice)
 {
  case 1:printf("Enter the item at front end: ");
		 scanf("%d",&item);
		 last=cir_insert_front(last,item);
		 break;
  case 2:printf("Enter the item at rear end: ");
		 scanf("%d",&item);
		 last=cir_insert_rear(last,item);
		 break;
  case 3:last=cir_delete_front(last);
	 break;
  case 4:last=cir_delete_rear(last);
	 break;
  case 5:display(last);
		 break;
  default:exit(0);
  }
 }
}
