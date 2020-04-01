#include<stdio.h>
typedef struct jobdef
{
    char id[5];
    int deadline;
    int profit;
}Job;
void display(Job jobs[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%10s",jobs[i].id);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%10d",jobs[i].deadline);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%10d",jobs[i].profit);
    printf("\n");
}
void sort(Job a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j].profit<a[j+1].profit)
            {
                Job c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
    }
}
void jobSequencing(Job jobs[],int n)
{
    int dmax=jobs[0].deadline; int i;
    for(i=0;i<n;i++)
    {
        if(jobs[i].deadline>dmax)
            dmax=jobs[i].deadline;
    }
    int jobSeqResult[dmax];
    for(i=0;i<n;i++)
        jobSeqResult[i]=-1;

    for(i=0;i<n;i++)
    {
        int k=jobs[i].deadline;
        while(k>0)
        {
            if(jobSeqResult[k-1]==-1)
            {
                jobSeqResult[k-1]=i;
                break;
            }
            k--;
        }
    }
    printf("\nSequence of JOBs are:\n");
    for(i=0;i<dmax;i++)
        printf("%s  ",jobs[jobSeqResult[i]].id);
    printf("\n");
    int tp=0;
    for(i=0;i<dmax;i++)
        tp=tp+(jobs[jobSeqResult[i]].profit);
    printf("\nTotal profit: %d",tp);
}
int main()
{
    int n,i;
    printf("Enter total number of jobs: ");
    scanf("%d",&n);
    Job jobs[n];
    for(i=0;i<n;i++)
    {
        printf("Enter details of %dth job\n",i+1);
        printf("Enter JOB ID: ");
        scanf("%s",jobs[i].id);
        printf("Enter DEADLINE: ");
        scanf("%d",&jobs[i].deadline);
        printf("Enter PROFIT: ");
        scanf("%d",&jobs[i].profit);
        printf("\n");
    }
    sort(jobs,n);
    printf("Jobs sorted in descending  order of their profit\n");
    display(jobs,n);
    jobSequencing(jobs,n);
    return 0;
}
