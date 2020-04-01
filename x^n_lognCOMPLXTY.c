#include<stdio.h>
int xpowern(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2==0)
    {
        int y=xpowern(x,n/2);
        return y*y;
    }
    else
        return x*xpowern(x,n-1);
}
int main()
{
    int x,n;
    printf("Enter value of x: ");
    scanf("%d",&x);
    printf("Enter value of n: ");
    scanf("%d",&n);
    printf("The value of x^n = %d",xpowern(x,n));
    return 0;
}
