#include<stdlib.h>
#include<iostream>
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
void create_no_loop()
{
    int x;
    struct node *temp,*p,*q;
    temp=head;
    p=create();
    cout<<"Enter the data to append in the list::";
    cin>>x;
    p->data=x;
    p->next=NULL;
    if(temp==NULL)
    {
        head=p;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
    }
}

void create_loop()
{
    struct node *l,*r;
    l=head;
    r=(l->next)->next;
    while(l->next!=NULL)
    {
        l=l->next;
    }
    l->next=r;
}

int  check_loop()
{
    struct node *temp1,*temp2;
    temp1=head;
    temp2=head;
    do
    {
        temp1=temp1->next;
        temp2=temp2->next;
        temp2=temp2!=NULL ? temp2->next:NULL;
    }
    while(temp1 && temp2);
    if(temp1==temp2)
        return(1);
    else
        return(0);
}


int main()
{
    int x,ch;
    /*
    x=linked_loop();

    if(x==1)
        cout<<"LOOP IS PRESENT\n";
    else
        count<<"LOOP IS NOT PRESENT\n";
    */

    while(1)
    {
        cout<<"\n1. CREATE LIST WITHOUT LOOP\n2. CREATE LIST LOOP\n";
        cout<<"3. CHECK LOOP PRESENT OR NOT\n4. EXIT\n";
        cout<<"Enter your choice :: ";
        cin>>ch;
        switch(ch)
        {
            case 1: create_no_loop();
                    break;
            case 2: create_loop();
                    break;
            case 3: x=check_loop();
                    if(x==1)
                        cout<<endl<<"NO  CYCLE  IS  PRESENT \n";
                    else
                        cout<<endl<<"LOOP  IS  PRESENT  \n";
                    break;
            case 4:exit(1);
            default:exit(1);
        }
    }
    return(0);
}
