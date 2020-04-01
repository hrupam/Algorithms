#include<stdio.h>
void sort(int a[],int b[],int c[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                int c0=a[j];
                a[j]=a[j+1];
                a[j+1]=c0;

                int c1=b[j];
                b[j]=b[j+1];
                b[j+1]=c1;

                int c2=c[j];
                c[j]=c[j+1];
                c[j+1]=c2;
            }
        }
    }
}
int main()
{
    int n,i,M;
    printf("Enter value of n: ");
    scanf("%d",&n);
    printf("Enter capacity of knapsack: ");
    scanf("%d",&M);
    int p[n],w[n];
    float pw[n];
    printf("Enter profits:\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("Enter weights:\n");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    for(i=0;i<n;i++)
        pw[i]=((float)p[i])/w[i];

    sort(pw,p,w,n);
    float tp=0;
    for(i=0;i<n;i++)
    {
        if(w[i]<=M && M!=0)
        {
            M=M-w[i];
            tp=tp+p[i];
        }
        else if(w[i]>M && M!=0)
        {
            float ratio=((float)M)/w[i];
            tp=tp+(ratio*p[i]);
            M=M-M;
        }
    }
    printf("Total profit= %f",tp);
    return 0;
}
