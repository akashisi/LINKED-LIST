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
    int x;
    struct node *temp,*p;
    temp=create();
    cout<<endl<<"Enter the data to append in the list :: ";
    cin>>x;
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
    while(1)
    {
        cout<<endl<<"1. Add element in th linked list\n2. DISPLAY content of linked list\n3. EXIT\n";
        cout<<endl<<"Enter your choice ::";
        cin>>ch;
        switch(ch)
        {
            case 1:append();
                   break;
            case 2:display();
                   break;
            case 3:exit(1);
                    break;
            default:exit;
        }
    }
    return(0);
}
