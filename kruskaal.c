#include<stdlib.h>
#include<stdio.h>
int parent[100],a[100][100],minCost=0;
int main()
{
    int n;
    printf("Please enter the number of vertices: ");
    scanf("%d",&n);
    printf("\nPlease enter the adjacency matrix: ");
    int i,j;
    for(i=0;i<n;i++)
        parent[i]=i;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j]=999;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
                a[i][j]=999;
        }
    }
    int ne=0,x,y,u,v;
    while(ne<n)
    {
        int min=999;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]<min)
                {
                    min=a[i][j];
                    x=u=i;
                    y=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(unions(u,v))
        {
            printf("\n%d %d",x,y);
            minCost+=min;
        }
        a[x][y]=999;
        a[y][x]=999;
        ne++;
    }
    printf("\nMincost: %d",minCost);
    return 1;
}
int unions(int u,int v)
{
    if(u!=v)
    {
        parent[u]=v;
        return 1;
    }
    return 0;
}
int find(int i)
{
    if(parent[i]==i)
        return i;
    else
        find(parent[i]);
}
