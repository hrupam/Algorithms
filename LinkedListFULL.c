#include<stdio.h>
#include<malloc.h>
typedef struct nodedef
{
    int num;
    struct nodedef *ptr;
}NODE;
NODE *temp=0; NODE *head=0; NODE *node;
void insert()
{
    int data;
    node=(NODE*)malloc(sizeof(NODE));
    printf("Enter data: ");
    scanf("%d",&data);
    node->num=data;
    node->ptr=0;
    if(head==0)
        head=temp=node;
    else
    {
        while(temp->ptr!=0)
            temp=temp->ptr;
        temp->ptr=node;
        temp=node;
    }
    printf("Node is inserted\n");
    temp=head;
}
void insertPos()
{
    temp=head;
    int pos; int ele;
    printf("Enter the position you want to insert element: ");
    scanf("%d",&pos);
    int x=1;
    while(x<pos-1)
    {
        temp=temp->ptr;
        x++;
    }
    node=(NODE*)malloc(sizeof(NODE));
    printf("Enter data: ");
    scanf("%d",&ele);
    node->num=ele;
    node->ptr=temp->ptr;
    temp->ptr=node;
    printf("Node is inserted\n");
    temp=head;
}
void insertBeg()
{
    temp=head;
    printf("Enter data: ");
    int data;
    scanf("%d",&data);
    node=(NODE*)malloc(sizeof(NODE));
    node->num=data;
    printf("Node is inserted\n");
    node->ptr=temp;
    head=temp=node;
}
void deleteEnd()
{
    temp=head;
    NODE *prevnode;
    while(temp->ptr!=0)
    {
        prevnode=temp;
        temp=temp->ptr;
    }
    prevnode->ptr=0;
    free(temp);
    temp=head;
}
void deleteBeg()
{
    temp=head;
    temp=temp->ptr;
    free(head);
    head=temp;
}
void deletePos()
{
    NODE *prevnode,*nextnode;
    temp=head;
    int n;
    printf("Enter position you want to delete: ");
    scanf("%d",&n);
    int x=1;
    while(x<n)
    {
       prevnode=temp;
       temp=temp->ptr;
       nextnode=temp->ptr;
       x++;
    }
    prevnode->ptr=nextnode;
    free(temp);
    temp=head;
}
void displayLL()
{
    temp=head;
    printf("\nThe Linked List is\n");
    while(temp!=0)
    {
        printf("%d  ",temp->num);
        temp=temp->ptr;
    }
    temp=head;
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1-Insert\n2-Insert at beginning\n3-Insert at any position\n4-Display\n5-Exit\n6-Delete at end\n7-Delete at beginning\n8-Delete at any position\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert();
            break;
        case 2:
            insertBeg();
            break;
        case 3:
            insertPos();
            break;
        case 4:
            displayLL();
            break;
        case 5:
            printf("Exited\n");
            return 0;
        case 6:
            deleteEnd();
            break;
        case 7:
            deleteBeg();
            break;
        case 8:
            deletePos();
            break;
        }
    }
}
