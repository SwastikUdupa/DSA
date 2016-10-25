#include<stdio.h>
int a[100],top=-1,isVisited[100];
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
void push(int ele)
{
    a[++top]=ele;
}
int pop()
{
    printf("%d\n",a[top]);
    return a[top--];
}
void dfs(int num)
{
    int i,j,vertex;
    for(i=0;i<num;i++)
        isVisited[i]=0;
    int adj[10][10];
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
            adj[i][j]=0;
    }
    for(i=0;i<num;i++)
    {
        for(j=i+1;j<num;j++)
        {
           printf("\nIs %d connected to %d?(0/1): ",i,j) ;
           int ch;
           scanf("%d",&ch);
           if(ch==1)
           {
               adj[i][j]=1;
               adj[j][i]=1;
           }
        }
    }
    printf("\nPlease enter the vertex to start: ");
    scanf("%d",&vertex);
    push(vertex);
    while(top!=-1)
    {
        int u=pop();
        if(!isVisited[u])
        {
            isVisited[u]=1;
            for(i=0;i<num;i++)
            {
                if(adj[u][i]&&!isVisited[i]&&(notInStack(i)||top==-1))
                    {
                        push(i);
                    }
            }
        }
    }

}
int main()
{
    int num,vertex;
    printf("Please enter the number of vertices: ");
    scanf("%d",&num);
    dfs(num);
    return 1;
}
