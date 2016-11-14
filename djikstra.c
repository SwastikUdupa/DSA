#include<stdio.h>
#include<stdlib.h>
void main()
{
    int num,i,j,a[10][10];
    printf("Please enter the size of the array: ");
    scanf("%d",&num);
    int *visited=(int *)malloc(num*sizeof(int));
    for(i=0;i<num;i++)
        visited[i]=0;
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
    int *final_arr=(int *)malloc(num*sizeof(int));
    for(i=0;i<num;i++)
        final_arr[i]=0;
    printf("Please enter the points whose shortest distance needs to be found: ");
    int vertex,y;
    scanf("%d %d",&vertex,&y);
    final_arr[vertex]=0;
    visited[vertex]=1;
    int lea=0,u,v;
    while(lea<num)
    {
        int min=999;
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                if(visited[i]&&(!visited[j])&&(a[i][j]+final_arr[i])<min)
                {
                    u=i;
                    v=j;
                    min=a[i][j]+final_arr[i];
                }
            }
        }
        if(visited[u]&&!visited[v])
        {
            printf("\n%d %d",u,v);
            final_arr[v]=min;
            visited[v]=1;
            a[u][v]=a[v][u]=999;
        }
        lea++;
    }
    printf("\nThe final array is:");
    for(i=0;i<num;i++)
        printf("%d ",final_arr[i]);
    printf("\nThe shortest distance between %d and %d is %d",vertex,y,final_arr[y]);
}
