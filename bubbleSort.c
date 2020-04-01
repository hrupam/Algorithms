#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubbleSort(int a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
    }
}
int main()
{
   int n,i;
   printf("Enter size of array: ");
   scanf("%d",&n);
   int a[n];
   for(i=0;i<n;i++)
        a[i]=rand()/100;
    clock_t t;
    t=clock();
    bubbleSort(a,n);
    t=clock()-t;
    double tt=((double)t)/CLOCKS_PER_SEC;
   /*printf("The sorted array is:\n");
   for(i=0;i<n;i++)
        printf("%d ",a[i]);*/
    printf("Execution Time: %f",tt);
    return 0;
}
