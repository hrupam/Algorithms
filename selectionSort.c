#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionSort(int a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        int c=a[i];
        a[i]=a[min];
        a[min]=c;
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
   selectionSort(a,n);
   /*printf("The sorted array is:\n");
   for(i=0;i<n;i++)
        printf("%d ",a[i]);*/
    t=clock()-t;
    double tt=((double)t)/CLOCKS_PER_SEC;
    printf("Execution Time: %f",tt);
   return 0;
}
