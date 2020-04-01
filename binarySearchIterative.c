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
int binSearch(int arr[], int l, int h, int x)
{
    while (l < h) {
        int m =(l+h)/2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            h = m - 1;
    }

    // if we reach here, then element was
    // not present
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
    /*printf("The sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);*/
    printf("Enter what to search: ");
    scanf("%d",&key);
    //clock_t t=clock();
    int check=binSearch(a,0,n-1,key);
    //t=clock()-t;
    if(check==-1)
        printf("%d not found",key);
    else
        printf("%d is found at position %d",key,check+1);
    /*double tt=((double)t)/CLOCKS_PER_SEC;
    printf("Execution Time: %f",tt);*/
    return 0;
}
