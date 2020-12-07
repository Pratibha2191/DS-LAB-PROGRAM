#include<stdio.h>
#include<conio.h>
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
NODE insert_rear(NODE first,int item)
{
NODE temp,cur;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL)
 return temp;
cur=first;
while(cur->link!=NULL)
 cur=cur->link;
cur->link=temp;
return first;
}
void display(NODE first)
{
 NODE temp;
 if(first==NULL)
  printf("list empty");

 for(temp=first;temp!=NULL;temp=temp->link)
  {
  printf("%d ",temp->info);
  }
  printf("\n");
}
NODE concat(NODE first,NODE second)
{
 NODE cur;
 if(first==NULL)
  return second;
 if(second==NULL)
  return first;
 cur=first;
 while(cur->link!=NULL)
  cur=cur->link;
 cur->link=second;
 return first;
}
NODE reverse(NODE first)
 {
 NODE cur,temp;
 cur=NULL;
 while(first!=NULL)
  {
   temp=first;
   first=first->link;
   temp->link=cur;
   cur=temp;
  }
 return cur;
}

void sort(NODE first)
{
    int swapped, i;
    NODE ptr1;
    NODE lptr=NULL;

    if (first == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = first;

        while (ptr1->link != lptr)
        {
            if (ptr1->info > ptr1->link->info)
            {
                swap(ptr1, ptr1->link);
                swapped = 1;
            }
            ptr1 = ptr1->link;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap( NODE a, NODE b)
{
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

void main()
{
int item,choice,pos,i,n;
NODE a,b;
for(;;)
{
printf("1.concatenate 2.sort 3.reverse 4.dislay 5.exit\n");
printf("enter the choice\n");
scanf("%d",&choice);
switch(choice)
 {
  case 1:printf("Enter the no of nodes in 1 :");
		 scanf("%d",&n);
		 a=NULL;
		 printf("Enter the items :\n");
		 for(i=0;i<n;i++)
		  {

		   scanf("%d",&item);
		   a=insert_rear(a,item);
		  }
		  printf("Enter the no of nodes in 2 :");
		 scanf("%d",&n);
		 b=NULL;
		 printf("Enter the items :\n");
		 for(i=0;i<n;i++)
		  {

		   scanf("%d",&item);
		   b=insert_rear(b,item);
		  }
		  a=concat(a,b);
		  printf("Concatenated list: ");
          display(a);
  case 2:sort(a);
         display(a);
         break;
  case 3:a=reverse(a);
		 display(a);
		 break;
  case 4:display(a);
		 break;
  default:exit(0);
  }
  }
  getch();
  }









