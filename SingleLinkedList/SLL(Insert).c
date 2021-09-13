#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
}*m,*first=NULL,*last,*n,*prev,*temp;

void create()
{
    int x;
    printf("enter a value : ");
    scanf("%d",&x);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    if(first==NULL)
    {
        first=n;
        last=n;
    }
    else
    {
        last->next=n;
        last=n;
    }
}
void insert_begin()
{
     int x;
    printf("enter a value : ");
    scanf("%d",&x);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    n->next=first;
    first=n;
}
void insert_end()
{
      int x;
    printf("enter a value : ");
    scanf("%d",&x);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    last->next=n;
    last=n;
}
void insert_before()
{
      int x,key;
    printf("enter a value : ");
    scanf("%d",&x);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    temp=first;
    printf("enter key : ");
    scanf("%d",&key);
    while(temp->next!=NULL)
    {
        if(temp->data==key)
        break;
        else
        {
            prev=temp;
            temp=temp->next;
        }
        n->next=temp;
        prev->next=n;
    }
}
void insert_after()
{
     int x,key;
    printf("enter a value : ");
    scanf("%d",&x);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    temp=first;
    printf("enter key : ");
    scanf("%d",&key);
    while(temp->next!=NULL)
    {
        if(temp->data==key)
        break;
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}
void display()
{
    m=first;
    while(m!=NULL)
    {
        printf("%d->",m->data);
        m=m->next;
    }printf("\n");
}
int main()
{
    int ch;
    printf("enter MENU\n");
    do{
        printf("1.create\n2.display\n3.insert_begin\n4.insert_end\n5.insert_before\n6.insert_after\n");
        printf("enter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
            break;
            case 2:display();
            break;
            case 3:insert_begin();
            break;
            case 4:insert_end();
            break;
            case 5:insert_before();
            break;
            case 6:insert_after();
            break;
        }
    }while(ch<=6);
}