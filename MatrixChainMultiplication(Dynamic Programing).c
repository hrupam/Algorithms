#include<stdio.h>
#include<limits.h>
void parenthesis(int a[],int n)
{
    int k=a[n-1];
    while(k!=0)
    {
        printf("\nParenthesisation should be done at %d",k);
        k=a[k];
    }
}
int main()
{
    int n;
    printf("Enter total number of matrices: ");
    scanf("%d",&n);
    n=n+1;
    int dim[n]; int i,j,k,d;
    printf("Enter the dimensions in a ordered sequence: ");
    for(i=0;i<n;i++)
        scanf("%d",&dim[i]);
    int m[n][n];int s[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            m[i][j]=0;
            s[i][j]=0;
        }
    }
    for(d=1;d<n-1;d++)
    {
        for(i=1;i<n-d;i++)
        {
            j=i+d;
            int min=INT_MAX;
            for(k=i;k<j;k++)
            {
                int val=m[i][k]+m[k+1][j]+dim[i-1]*dim[k]*dim[j];
                if(val<min)
                {
                    min=val;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }
    }
    printf("Total number of matrix multiplications required = %d\n",m[1][n-1]);

    int s1[n];
    for(i=0;i<n;i++)
        s1[i]=s[1][i];
    parenthesis(s1,n);
    return 0;
}
