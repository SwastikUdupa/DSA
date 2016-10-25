#include<stdio.h>
int top=-1,front=-1,visited[100];
int a[100];
int notInStack(int x)
{
int i;
	for(i=0;i<=top;i++)
	{
		if(a[i]==x)
			return 0;
	}
return 1;
}
int dequeue()
{
    printf("%d\n",a[front+1]);
   return a[++front] ;
}
void enqueue(int ele)
{
    a[++top]=ele;
}
void bfs()
{
    int i,j,num,vertex,ch;
    printf("Please enter the number of vertices: ");
    scanf("%d",&num);
    int adj[10][10];
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
            adj[i][j]=0;
    }
    for(i=0;i<num;i++)
        a[i]=0;
    for(i=0;i<num;i++)
    {
        for(j=i+1;j<num;j++)
        {
            printf("Is %d connected to %d?(0/1): ",i,j);
            scanf("%d",&ch);
            if(ch)
            {
                adj[i][j]=1;
                adj[j][i]=1;
            }
        }
    }
    printf("\nPlease enter the starting vertex: ");
    scanf("%d",&vertex);
    enqueue(vertex);
    while(front<top)
    {
        int u=dequeue();
        if(!visited[u])
        {
            visited[u]=1;
            for(i=0;i<num;i++)
            {
                if(adj[u][i]&&!visited[i]&&(notInStack(i)||front==top))
                {
                    enqueue(i);
                }
            }
        }

    }
}
int main()
{
    bfs();
    return 1;
}
