#include<stdio.h>
#define CAP 5
int front=-1,rear=-1;
int a[CAP];
void insert()
{
    if(front==0 && rear==CAP-1)
        printf("Queue is full\n");
    else
    {
        int item;
        printf("Enter the element to insert: ");
        scanf("%d",&item);
        if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
        }
        else
            rear+=1;
        a[rear]=item;
    }
}
void delete()
{
    if(front==-1 && rear==-1)
        printf("Queue is empty\n");
    else
    {
        if(front==0 && rear==0)
        {
            printf("%d is deleted\n",a[front]);
            front=-1; rear=-1;
        }
        else
        {
            int i;
        printf("%d is deleted\n",a[front]);
        for(i=front+1;i<=rear;i++)
            a[i-1]=a[i];
        rear-=1;
        }

    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)
        printf("Queue is empty\n");
    else
    {
    printf("The queue is\n");
    for(i=front;i<=rear;i++)
        printf("%d ",a[i]);
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1-Insert\n2-Delete\n3-Print\n4-Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Process exited...");
            return 0;
        }

    }
}
