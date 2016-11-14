#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *next;
    int data;
}*header=NULL;
void push(int ele)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;
    if(header==NULL)
    {
        header=temp;
    }
    else
    {
        struct node *temp2=header;
        while(temp2->next!=NULL)
            temp2=temp2->next;
        temp2->next=temp;
    }
}
void pop()
{
    struct node *temp=header;
    if(header==NULL)
        printf("Underflow");
    else if(header->next==NULL)
    {
        printf("%d",header->data);
        header=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
            temp=temp->next;
        printf("%d\n",temp->next->data);
        temp->next=NULL;
    }

}
void display()
{
    struct node *temp=header;
    if(header==NULL)
        printf("\nNothing to display!");
    else
    {
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
void main()
{
    int ch,i,j,ele;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Quit\n");
        printf("Please enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nPlease enter the element to be pushed: ");
            scanf("%d",&ele);
            push(ele);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        }
    }while(ch!=4);
}
