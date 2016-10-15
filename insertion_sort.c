#include<stdio.h>
#include<stdlib.h>
void isort(int *a,int len)
{
    int i;
    for(i=1;i<=len;i++)
    {
        int ele=a[i];
        int j=i;
        while(j>=1&&a[j-1]>ele)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=ele;
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
    isort(a,n-1);
    printf("The array after sorting is as follows:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

