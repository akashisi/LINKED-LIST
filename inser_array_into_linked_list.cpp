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
void append(int a[],int n)
{
    int i;
    struct node *temp,*p;
    for(i=0;i<n;i++)
   {
    temp=create();
    //cout<<endl<<"Enter the data to append in the list :: ";
    //cin>>x;
    temp->data=a[i];
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
    int ch,n;
    int a[]={9,0,4,5,6,7,0,0,6,4};
    n=sizeof(a)/sizeof(a[0]);
    cout<<endl<<"Content of ARRAY ::\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    append(a,n);
    display();
    return(0);
}

