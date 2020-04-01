#include<stdio.h>
#include<stdlib.h>
int linSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
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
    /*printf("The sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);*/
    printf("\nEnter what to search: ");
    scanf("%d",&key);
    int check=linSearch(a,n,key);
    if(check==-1)
        printf("%d not found",key);
    else
        printf("%d is found at position %d",key,check+1);
    return 0;
}
