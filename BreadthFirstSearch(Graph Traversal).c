#include<stdio.h>
#include<stdbool.h>
#include<conio.h>
#define V 5 //change the macro for no. of vertices
void BFS(int graph[V][V],int source)
{
    bool visited[V];
    int i;
    for(i=0;i<V;i++)
        visited[i]=false;
    int queue[V]; int front=0,rear=0;
    queue[rear]=source;
    rear=rear+1;
    visited[source]=true;
    int result[V];
    int index=0;
    result[index]=source;
    int k;
    for(k=front;k<V;k++)
    {
        int i=queue[k]; int j;
        for(j=0;j<V;j++)
        {
            if(graph[i][j]==1 && visited[j]==false)
            {
                queue[rear]=j;
                rear++;
                visited[j]=true;
                result[++index]=j;
            }
        }
        front++;
    }
    printf("\nThe BFS result as a source vertex %d:\n",source);
    for(index=0;index<V;index++)
        printf("%d, ",result[index]);

}
void display(int graph[V][V])
{
    int i,j;
    printf("\nThe adjacency matrix is\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            printf("%3d",graph[i][j]);
        printf("\n");
    }
}
int main()
{
    int graph[V][V]; int i,j;
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<V;i++)
    {
        printf("Enter values of %dth row\n",i+1);
        for(j=0;j<V;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    int source;
    printf("Enter source vertex: ");
    scanf("%d",&source);
    display(graph);
    BFS(graph,source);
    printf("\nEnter a key to exit...");
    getch();
    return 0;
}
