#include<stdio.h>
#include<stdlib.h>
typedef struct nodedef
{
    int num;
    struct nodedef *ptr;
}NODE;
NODE *head=0;
NODE *temp=0;
NODE *node;
void insertBeg()
{
    temp=head;
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    node=(NODE*)malloc(sizeof(NODE));
    node->num=data;
    node->ptr=temp;
    printf("Node is inserted at beginning\n");
    head=temp=node;
}
void insertEnd()
{
    temp=head;
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    node=(NODE*)malloc(sizeof(NODE));
    node->num=data;
    node->ptr=0;
    while(temp->ptr!=0)
    {
        temp=temp->ptr;
    }
    temp->ptr=node;
    printf("Node is inserted at end\n");
    temp=head;
}
void insertPos()
{
    temp=head;
    int item,data; int ctr=0;
    printf("Enter the data: ");
    scanf("%d",&data);
    printf("After which number you want to insert the node ? : ");
    scanf("%d",&item);
    node=(NODE*)malloc(sizeof(NODE));
    node->num=data;
    while(temp!=0)
    {
        if(temp->num==item)
        {
            node->ptr=temp->ptr;
            temp->ptr=node;
            ctr=1;
            printf("Node is inserted after %d\n",item);
            break;
        }
        temp=temp->ptr;
    }
    if(ctr==0)
        printf("Item not found\n");
    temp=head;
}
void displayLL()
{
    temp=head;
    printf("The data are:\n");
    while(temp!=0)
    {
        printf("%d  ",temp->num);
        temp=temp->ptr;
    }
    temp=head;
}
int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    int x=1;
    while(x<=n)
    {
        int data;
        printf("Enter data: ");
        scanf("%d",&data);
        node=(NODE*)malloc(sizeof(NODE));
        node->num=data;
        node->ptr=0;
        if(head==0)
            head=temp=node;
        else
        {
            temp->ptr=node;
            temp=node;
        }
        x++;
    }
    temp=head;
    while(1)
    {
        int ch;
        printf("\n1-Insert node at beginning\n2-Insert node at end\n3-Insert node after a number\n4-Display Linked List\n5-Exit process\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insertBeg();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertPos();
            break;
        case 4:
            displayLL();
            break;
        case 5:
            printf("Process exited...");
            return 0;
        }
    }
    return 0;
}
