#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,u,v,vertex,num;
    printf("Please enter the number of vertices: ");
    scanf("%d",&num);
    int a[10][10];
    printf("Please enter the adjacency matrix: ");
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
                a[i][j]=999;
        }
    }
    int k;
    while(k<num)
    {
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                if(i!=j)
                {
                    if(a[i][k]+a[k][j]<a[i][j])
                        a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
        k++;
    }
    printf("\nThe distance matrix is: \n");
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
