#include<stdio.h>
#include<limits.h>
//Author- Rupam Hari
void bellmanFord(int graph[][3], int V, int E, int source)
{
    int dist[V]; int i,j;
    for(i=0;i<V;i++)
        dist[i]=INT_MAX;
    dist[source]=0;

    for(i=0;i<V-1;i++)
    {
        for(j=0;j<E;j++)
        {
            if(dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]])
                dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
        }
    }

    printf("Distance of vertices from source %d are as follows:-\n",source);
    for(i=0;i<V;i++)
        printf("%d --> %d is %d\n",source,i,dist[i]);

    for(j=0;j<E;j++)
        {
            if(dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]])
                printf("\nThe graph contains negative weight cycle.\nHence, the single source shortest path cannot be found using\nBellman-Ford algorithm.\n");
        }
}
int main()
{
    int V,E,source; int i,j;
    printf("Enter number of vertices: ");
    scanf("%d",&V);
    printf("Enter number of edges: ");
    scanf("%d",&E);
    int graph[E][3]; int edge[3];
    printf("Enter the weighted edges in the form [source vertex,end vertex,weight]\n");
    for(i=0;i<E;i++)
    {
        printf("Edge %d: ",i+1);
        scanf("%d %d %d",&edge[0],&edge[1],&edge[2]);
        for(j=0;j<3;j++)
            graph[i][j]=edge[j];
    }
    printf("Enter source vertex: ");
    scanf("%d",&source);
    bellmanFord(graph,V,E,source);
    return 0;
}
