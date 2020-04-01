#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int c=*x;
    *x=*y;
    *y=c;
}
int main()
{
    int a[]={0,2,5,4};
    swap(&a[0],&a[3]);
    int i;
    for(i=0;i<4;i++)
        printf("%d ",a[i]);
    return 0;
}
