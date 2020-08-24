#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

struct node *create()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    return(temp);
};
void append()
{
    int x=5;
    struct node *temp,*p;
    for(int i=0;i<5;i++)
   {
    temp=create();
    temp->data=x;
    temp->next=NULL;
    p=head;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
    x=x+10;
   }
}
void display()
{
    struct node *temp;
    temp=head;
    cout<<endl<<"CONTENT OF LINKED LSIT ::\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    int ch;
    append();
    display();
    return(0);
}
