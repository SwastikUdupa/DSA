#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    struct node *right;
    int key;
}*header=NULL;
struct node* newNode(int key)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->key=key;
    return temp;
};
struct node* insertNode(struct node *root,int key)
{
    if(root==NULL)
        return newNode(key);
    else
    {
        if(key>root->key)
            root->right=insertNode(root->right,key);
        else
            root->left=insertNode(root->left,key);
    }

}
struct node* minNode(struct node *root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}
struct node *deleteNode(struct node* root,int key)
{
    if(root==NULL)
        return root;
    if(root->key>key)
        root->left=deleteNode(root->left,key);
    else if(root->key<key)
        root->right=deleteNode(root->right,key);
    else
    {
        if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        struct node *temp=minNode(root->right);
        root->key=temp->key;
        root->right=deleteNode(root->right,key);
    }
    return root;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}
main()
{
    struct node *root=NULL;
    int ch,ele;
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Quit");
    do
    {
            printf("Please enter your option:");

            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                printf("\nPlease enter the element to be inserted: ");
                scanf("%d",&ele);
                if(root==NULL)
                    root=newNode(ele);
                else
                    insertNode(root,ele);
                break;
            case 2:
                printf("Please enter the element to be deleted: ");
                scanf("%d",&ele);
                deleteNode(root,ele);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                break;
            }
    }while(ch!=4);
}
