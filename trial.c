#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
heapify(int *a,int i,int size)
{
    int l=2*i+1;
    int r=2*i+2;
    int greatest=i;
    if(l<size&&a[l]>a[greatest])
        greatest=l;
    if(r<size&&a[r]>a[greatest])
        greatest=r;
    if(greatest!=i)
        {
            int temp=a[i];
            a[i]=a[greatest];
            a[greatest]=temp;
            heapify(a,greatest,size);
        }
}
void heapSort(int *a,int size)
{
    int i;
    for(i=size/2-1;i>=0;i--)
        heapify(a,i,size);
    for (int i=size-1; i>=0; i--)
{
    // Move current root to end

    int temp=a[0];
    a[0]=a[i];
    a[i]=temp;
    // call max heapify on the reduced heap
    heapify(a,0,i);
}
}
int main()
{
    int num,i,j;
    printf("Please enter the number of elements: ");
    scanf("%d",&num);
    int *a=(int *)malloc(num*sizeof(int));
    printf("Please enter the numbers: ");
    for(i=0;i<num;i++)
        scanf("%d",&a[i]);
    heapSort(a,num);
    printf("\nAfter sorting: ");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);
    return 0;
}
