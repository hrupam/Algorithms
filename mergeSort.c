#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int low,int mid,int high)
{
    int i,j,k;
    int n1=mid-low+1;
    int n2=high-mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=a[low+i];
    for(j=0;j<n2;j++)
        R[j]=a[mid+1+j];

    i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            a[k++]=L[i++];
        else
            a[k++]=R[j++];
    }
    while(i<n1)
        a[k++]=L[i++];
    while(j<n2)
        a[k++]=R[j++];
}
void mergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
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
   mergeSort(a,0,n-1);
   t=clock()-t;
    double tt=((double)t)/CLOCKS_PER_SEC;
   /*printf("The sorted array is:\n");
   for(i=0;i<n;i++)
        printf("%d ",a[i]);*/
   printf("Execution Time: %f",tt);
   return 0;
}
