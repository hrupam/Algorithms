#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int c=*x;
    *x=*y;
    *y=c;
}
int partition(int a[],int low, int high)
{
    //int mid=(low+high)/2;
    int pivot=a[low];
    int start=low;
    int end=high;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
            swap(&a[start],&a[end]);
    }
    swap(&a[end],&a[low]);
    return end;
}
void quickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int pos=partition(a,low,high);
        quickSort(a,low,pos-1);
        quickSort(a,pos+1,high);
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
   quickSort(a,0,n-1);
   /*printf("The sorted array is:\n");
   for(i=0;i<n;i++)
        printf("%d ",a[i]);*/
   return 0;
}
