#include<stdio.h>
#define CAP 5
int top=-1,i;
int a[CAP];
void push()
{
    int item;
    if(top+1==CAP)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter the item: ");
        scanf("%d",&item);
        a[++top]=item;
        printf("After pushing item, the stack is\n");
        display();
    }
}
void pop()
{
    if(top==-1)
        printf("Stack Underflow\n");
        else
            printf("The popped out item is %d\n",a[top--]);
}
void display()
{
    if(top!=-1)
    {
        printf("The stack is\n");
        for(i=top;i>-1;i--)
        printf("|  %d  |\n",a[i]);
    }
    else
        printf("The stack is empty\n");

}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1- Push item into the stack\n2- Pop item from the stack\n3- Display the stack\n4- Exit Process\nEnter your choice: ");
        scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Process exited...\n");
                return 0;
                break;
            default:
                printf("Wrong choice\n");
                break;
            }
    }
}

