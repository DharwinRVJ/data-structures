/*
pushing 10,20,30 to stack
displaying stack elements
->10->20->30
The top element in stack is 30
The popped element is 30
displaying stack elements
->10->20
*/
#include <stdio.h>
int stack[5], top = -1, MAX = 5;
int isfull();
int isempty();
int peek();
void push(int);
void pop();
void display();
int main()
{
    printf("pushing 10,20,30 to stack");
    push(10);
    push(20);
    push(30);
    display();
    printf("\nThe top element in stack is %d", peek());
    pop();
    display();
    return 0;
}
int isfull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int x)
{
    if (isfull())
        printf("\nStack is full\n");
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (isempty())
        printf("\nstack is empty, cannot remove");
    else
    {
        printf("\nThe popped element is %d", stack[top]);
        top--;
    }
}
void display()
{
    int i;
    printf("\ndisplaying stack elements\n");
    for (i = 0; i <= top; i++)
        printf("->%d", stack[i]);
}
int peek()
{
    return stack[top];
}