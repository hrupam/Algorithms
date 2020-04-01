#include<stdio.h>
#include<stdlib.h>
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
int binSearch(int a[],int low,int high,int key)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(key<a[mid])
            return binSearch(a,low,mid-1,key);
        else
            return binSearch(a,mid+1,high,key);
    }
    else
        return -1;
}
int main()
{
    int n,i,key;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        a[i]=rand()/100;
    insertionSort(a,n);
    printf("The sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("Enter what to search: ");
    scanf("%d",&key);
    int check=binSearch(a,0,n-1,key);
    if(check==-1)
        printf("%d not found",key);
    else
        printf("%d is found at position %d",key,check+1);
    return 0;
}
