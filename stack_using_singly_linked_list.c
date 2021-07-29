/*
Linked list implementation of stack
pushing 10,20,30 to stack
The stack elements are
->30->20->10
The top most element is 30
The popped element is 30
The stack elements are
->20->10
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * top;
void push(int);
void pop();
void display();
int peek();
int isempty();
int main()
{
    printf("Linked list implementation of stack\n");
    printf("pushing 10,20,30 to stack");
    push(10);
    push(20);
    push(30);
    display();
    printf("The top most element is %d\n",peek());
    pop();
    display();
    return 0;
}
int isempty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
void push(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (isempty())
        top = newnode;
    else
    {
        newnode->next = top;
        top = newnode;
    }
}
void pop()
{
    struct node *temp;
    temp = top;
    if (isempty())
        printf("The stack is empty");
    else
    {
        printf("The popped element is %d", temp->data);
        top = top->next;
        free(temp);
    }
}
int peek()
{
    return top->data;
}
void display()
{
    struct node *temp;
    temp = top;
    printf("\nThe stack elements are\n");
    while (temp != NULL)
    {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}