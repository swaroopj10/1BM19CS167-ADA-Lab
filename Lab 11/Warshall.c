#include<stdio.h>
#define V 4

void printSolution(int dist[][V]);

int min(int i,int j)
{
  if(i<j)
    return i;
  return j;
}

void floyd(int A[][4])
{
  int i,j,k,P[4][4];        

  for(i=0;i<4;i++)
     for(j=0;j<4;j++)
        P[i][j]=A[i][j];

  for(k=0;k<4;k++)            
      for(i=0;i<4;i++)       
          for(j=0;j<4;j++)  
               if(P[i][k]==1 && P[k][j]==1)
                 P[i][j]=1;

   printSolution(P);
}

void printSolution(int dist[][V])   
{
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
                printf ("%d", dist[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int graph[V][V] = { {0,1,0,0},
                        {0,0,0,1},
                        {0,0,0,0},
                        {1,0,1,0}
                      };
    printf("\n\n");
    floyd(graph);
    return 0;
}