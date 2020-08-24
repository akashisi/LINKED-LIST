#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

int count_nodes()
{
    struct node *temp;
    temp=head;
    int c=0;
    while(temp->next!=NULL)
    {
        c++;
        temp=temp->next;
    }
}

struct node *create()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    return(temp);
};

void append()
{
    struct node *temp,*p;
    temp=head;
    p=create();
    cout<<endl<<"Enter the data to add at end ::";
    cin>>p->data;
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
void add_at_head()
{
    struct node *temp,*p;
    p=head;
    temp=create();
    cout<<endl<<"Enter the data to add at HEAD ::";
    cin>>temp->data;
    temp->next=head;
    head=temp;
}
void add_at_any_position()
{
    int position,i=0;
    struct node *temp,*p;
    p=head;
    temp=create();
    cout<<endl<<"Enter the position at which add the data :: ";
    cin>>position;
    cout<<endl<<"Enter the data to add at any position(except 1st & last) ::";
    cin>>temp->data;
    for(i=1;i<position-1;i++)
    {
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
}
void delete_last_node()
{
    struct node *temp;
    temp=head;
    while((temp->next)->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}

void delete_head_node()
{
    head=head->next;
}

void delete_random_node()
{
    int i,x;
    struct node *temp,*p;
    temp=head;
    p=temp->next;
    cout<<endl<<"Enter the position to delete the node ::";
    cin>>x;

    for(i=1;i<x-1;i++)
    {
        temp=temp->next;
        p=p->next;
    }
    temp->next=p->next;
}

void display()
{
    struct node *temp;
    temp=head;
    cout<<endl<<"CONTENT OF LINKED LIST ::\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main()
{
    int choice;

    while(1)
    {
        cout<<endl<<"1. APPEND(ADD AT LAST)\n2. ADD AT HEAD\n3. ADD AT ANY POSITION\n";
        cout<<"4. DELETE LAST NODE\n5. DELETE HEAD NODE\n6. DELETE RANDOM NODE\n";
        cout<<"7. DISPLAY\n8. EXIT\n";
        cout<<"Enter your choice :: ";
        cin>>choice;
        switch(choice)
        {
            case 1: append();
                    break;
            case 2: add_at_head();
                    break;
            case 3: add_at_any_position();
                    break;
            case 4: delete_last_node();
                    break;
            case 5: delete_head_node();
                    break;
            case 6: delete_random_node();
                    break;
            case 7: display();
                    break;
            case 8: exit(1);
            default:exit(1);
        }
    }
}
