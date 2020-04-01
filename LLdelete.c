#include<stdio.h>
#include<malloc.h>
typedef struct nodedef
{
	int num;
	struct nodedef *ptr;
}NODE;
NODE *head,*node,*temp;

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
	printf("The LinkedList is:\n");
	while(temp!=0)
	{
		printf("%d  ",temp->num);
		temp=temp->ptr;
	}
	temp=head;
	printf("\n\n");
}

int main()
{
	head=0;
	temp=0;
	int n;
	printf("Enter no. of nodes: ");
	scanf("%d",&n);
	int x=1;
	while(x<=n)
	{
		node=(NODE*)malloc(sizeof(NODE));
		printf("Enter the data: ");
		scanf("%d",&node->num);
		if(head==0)
			head=temp=node;
		else
		{
			temp->ptr=node;
		    temp=node;
		}
		x++;
	}
	temp->ptr=0;
	int ch;
	while(1)
	{
		
	printf("\n1-Delete at beginning\n2-Delete at end\n3-Delete at any position\n4-Display\n5-Exit\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			deleteBeg();
			break;
		case 2:
			deleteEnd();
			break;
		case 3:
			deletePos();
			break;
		case 4:
			displayLL();
			break;
		case 5:
			printf("Process Exited");
			return 0;		
	}
    }
}
	
