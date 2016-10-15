#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int *a,int low,int high)
{
    int ele=a[high];
    int i=low-1,j=low;
    for(j=low;j<high;j++)
    {
        if(a[j]<=ele)
        {
            i=i+1;
            swap(&a[j],&a[i]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}
void qksort(int *a,int low,int high)
{
    if(low<high)
    {
        int p=partition(a,low,high);
        qksort(a,low,p-1);
        qksort(a,p+1,high);
    }
}
main()
{
    int n;
    printf("Please enter the number of elements: ");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    printf("\nPlease enter the elements:");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qksort(a,0,n-1);
    printf("The array after sorting is as follows:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
