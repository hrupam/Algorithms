#include<stdio.h>
int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

void knapsack(int p[],int wt[],int m,int n)
{
    int k[n+1][m+1];
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                k[i][j]=0;
            else if(wt[i]<=j)
                k[i][j]=max(p[i]+k[i-1][j-wt[i]] , k[i-1][j]);
            else
                k[i][j]=k[i-1][j];
        }
    }
    printf("Total profit= %d",k[n][m]);

    /*printf("The array\n\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d ",k[i][j]);
        }
        printf("\n"):
    }*/
}

int main()
{
    int i;
    int m,n;
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter size of knapsack: ");
    scanf("%d",&m);
    int p[n+1]; int wt[n+1];
    p[0]=0;wt[0]=0;
    printf("Enter profits:\n");
    for(i=1;i<n+1;i++)
        scanf("%d",&p[i]);
    printf("Enter weights:\n");
    for(i=1;i<n+1;i++)
        scanf("%d",&wt[i]);
    knapsack(p,wt,m,n);
    return 0;
}
