#include<stdio.h>
int minCost=0;
main()
{
    printf("Please enter the number of vertices: ");
    int num;
    scanf("%d",&num);
    int i,j,k,u,v;
    int a[10][10],visited[100],int arr[10];
    for(i=0;i<num;i++)
        arr[i]=i;
    printf("Please enter the adjacency matrix: ");
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
                a[i][j]=999;
        }
        visited[i]=0;
    }

    printf("Please enter a vertex: ");
    int vertex;
    scanf("%d",&vertex);
    visited[vertex]=1;
    int ne;
    while(ne<num)
    {
        int min=999,flag=0;
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                if(visited[i]&&a[i][j]<min&&!visited[j])
                {
                    min=a[i][j];
                    u=i;
                    v=j;
                    flag=1;
                }
            }
        }
        if(flag)
        {
            visited[v]=1;
            printf("The edge is %d to %d\n",u,v);
            minCost+=a[u][v];
            a[u][v]=a[v][u]=999;
        }
        ne++;
    }
    printf("The minimum cost is:%d",minCost);
}
