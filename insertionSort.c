#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertionSort(int a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int k=a[i]; j=i-1;
        while(j!=-1 && a[j]>k)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
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
   insertionSort(a,n);
   /*printf("The sorted array is:\n");
   for(i=0;i<n;i++)
        printf("%d ",a[i]);*/
        t=clock()-t;
    double tt=((double)t)/CLOCKS_PER_SEC;
    printf("Execution Time: %f",tt);
   return 0;
}
