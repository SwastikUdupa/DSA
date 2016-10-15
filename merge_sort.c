#include<stdio.h>
#include<stdlib.h>
void merge(int *a,int low,int mid,int high)
{
    int *x=(int *)malloc((mid-low+1)*sizeof(int));
    int *y=(int *)malloc((high-mid)*sizeof(int));
    int i,k=0;
    for(i=low;i<=mid;i++)
        x[k++]=a[i];
    k=0;
    for(i=mid+1;i<=high;i++)
        y[k++]=a[i];
    int j=0;
    i=low,k=0;
    while(k<mid-low+1&&j<high-mid)
    {
        if(x[k]>y[j])
            a[i++]=y[j++];
        else
            a[i++]=x[k++];
    }
    while(k<mid-low+1)
        a[i++]=x[k++];
    while(j<high-mid)
        a[i++]=y[j++];
}
void mergeSort(int *a,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
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
    mergeSort(a,0,n-1);
    printf("The array after sorting is as follows:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
