struct node
{
    struct node *next;
    int data;
}header=NULL;
void add(int pos,int ele)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=ele;
    if(header==NULL)
        header=temp;
    if(pos==0)
    {
        if(header!=temp)
        {
            temp->next=header;
            header=temp;
        }
    }
    else
    {
        int i=0;
        struct node *temp2=header;
        while(i<pos)
        {
            temp2=temp2->next;
            i++;
        }
        if(temp->next==NULL)

    }
}
