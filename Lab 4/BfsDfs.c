#include<stdio.h>
#include<stdlib.h>

int a[50][50], n, visited[50];
int q[20];
int s[20], top = -1, count=0;

void dfs(int v)
{
    int i;
    visited[v]=1;
    for(i=1;i<=n;i++)
    {
        if(a[v][i] && !visited[i])
        {
            printf("   %d->%d",v,i);
            dfs(i);
        }   
    }
    for(i=1;i<=n;i++)
    {
        if(visited[i])
        count++;
    }
    if(count==n)
    {
        printf("\n Graph is connected");
    }
    else
    {
        printf("\n Graph is not connected");
    }
   

}

void bfs(int v)
{
    int front = -1,rear = -1;
    int i, cur;
    visited[v] = 1;
    q[++rear] = v;
    while(front!=rear)
    {
        cur = q[++front];
        for(i=v;i<=n;i++)
        {
            if((a[cur][i]==1)&&(visited[i]==0))
            {
                q[++rear] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}



int main()
{

    int s,j;
    printf("\nEnter the number of vertices in graph:  ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(int i=1; i<=n; i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Enter the starting vertex\n");
    scanf("%d",&s);
    printf("\nNodes reachable from starting vertex %d are: ", s);
    bfs(s);

    dfs(1);  
     
}