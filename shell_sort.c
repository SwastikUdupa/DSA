#include<stdio.h>
#include<stdlib.h>
void shellsort(int *a,int len)
{
    int i,j,k;
    for(i=len/2;i>=1;i/=2)
    {
        for(j=i;j<=len;j+=i)
        {
            int ele=a[j];
            int k=j;
            while(k>=i&&a[k-i]>ele)
            {
                a[k]=a[k-i];
                k-=i;
            }
            a[k]=ele;
        }
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
    shellsort(a,n-1);
    printf("The array after sorting is as follows:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
