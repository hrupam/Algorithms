#include <stdio.h>
#define CAP 5
int front=-1,rear=-1,i;
int a[CAP];
void insert()
{
    if((front==0 && rear==CAP-1) || rear+1==front)
        printf("Queue is full\n");
    else
    {
        int item;
        printf("Enter the element: ");
        scanf("%d",&item);
        if(rear==-1)
        {
            front=0;
            rear=0;
        }
        else if(rear==CAP-1)
            rear=0;
        else
            rear+=1;
        a[rear]=item;
        printf("%d is inserted\n",item);
    }
}
void delete()
{
    if(front==-1)
        printf("Queue is empty\n");
    else
    {
        if(front==rear)
        {
        printf("%d is deleted\n",a[front]);
        front=-1; rear=-1;
        }
        else if(front==CAP-1)
                {
                    printf("%d is deleted\n",a[front]);
                        front=0;

                }
        else
        printf("%d is deleted\n",a[front++]);
    }

}
void display()
{
    if(front<rear)
    {
        for(i=front;i<=rear;i++)
            printf("%d ",a[i]);
    }
    else if(rear<front)
    {
        for(i=front;i<CAP;i++)
            printf("%d ",a[i]);
        for(i=0;i<=rear;i++)
            printf("%d ",a[i]);
    }
    else if(front==-1 && rear==-1)
        printf("Queue is empty\n");
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1-Insert element\n2-Delete element\n3-Print the queue\n4-Exit process\nEnter your choice: ");
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
            printf("Process exited\n");
            return 0;
        }
    }
}
