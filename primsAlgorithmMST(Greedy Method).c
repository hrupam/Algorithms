#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<conio.h>
#define V 5
int minkey(int key[], bool mstSet[])
{
    int min=INT_MAX; int minIndex; int i;
    for(i=0;i<V;i++)
    {
        if(mstSet[i]==false && key[i]<min)
        {
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void printMST(int graph[V][V], int parent[])
{
    int i;
    printf("        Edge      Weight\n");
    for(i=1;i<V;i++)
        printf("%10d-%d %10d\n",parent[i],i,graph[i][parent[i]]);
}
int primMST(int graph[V][V])
{
    int parent[V];
    bool mstSet[V];
    int key[V];
    int i,v;
    for(i=0;i<V;i++)
    {
        mstSet[i]=false;
        key[i]=INT_MAX;
    }
    int source;
    printf("Enter source vertex: ");
    scanf("%d",&source);
    key[source]=0;
    parent[source]=-1;

    for(i=0;i<V-1;i++)
    {
        int u= minkey(key,mstSet);
        mstSet[u]=true;
        for(v=0;v<V;v++)
        {
            if(graph[u][v]!=0 && mstSet[v]==false && graph[u][v]<key[v])
            {
                parent[v]=u; key[v]=graph[u][v];
            }
        }
    }
    printMST(graph,parent);
}
int main()
{
    int graph[V][V];
    int i,j;
    printf("Enter the Adjacency matrix of the graph\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            scanf("%d",&graph[i][j]);
    }
    primMST(graph);
    getch();
    return 0;
}
