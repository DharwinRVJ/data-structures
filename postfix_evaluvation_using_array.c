/*
Enter postfix expression: 252*+2/1%
Evaluation: 0
*/
#include <stdio.h>
#include <string.h>
int stack[20];
int top = -1;
int MAX = 20;
char postfix[20];
int isfull();
int isempty();
void push(int);
int pop();
void postfixeval();
int main()
{
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    postfixeval();
    printf("Evaluation: %d", pop());
    return 0;
}
int isfull()
{
    if (top >= MAX - 1)
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
int pop()
{
    int data = 0;
    if (isempty())
    {
        printf("\nstack is empty, cannot remove\n");
        return 0;
    }
    else
    {
        data = stack[top];
        top--;
        return data;
    }
}
void postfixeval()
{
    int i, value1 = 0, value2 = 0, data = 0;
    char symbol;
    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        switch (symbol)
        {
        case '0':
            push(0);
            break;
        case '1':
            push(1);
            break;
        case '2':
            push(2);
            break;
        case '3':
            push(3);
            break;
        case '4':
            push(4);
            break;
        case '5':
            push(5);
            break;
        case '6':
            push(6);
            break;
        case '7':
            push(7);
            break;
        case '8':
            push(8);
            break;
        case '9':
            push(9);
            break;
        case '+':
            if (top >= 1)
            {
                value1 = pop();
                value2 = pop();
                push((value2 + value1));
            }
            break;
        case '-':
            if (top >= 1)
            {
                value1 = pop();
                value2 = pop();
                push((value2 - value1));
            }
            break;
        case '*':
            if (top >= 1)
            {
                value1 = pop();
                value2 = pop();
                push((value2 * value1));
            }
            break;
        case '/':
            if (top >= 1)
            {
                value1 = pop();
                value2 = pop();
                push((value2 / value1));
            }
            break;
        case '%':
            if (top >= 1)
            {
                value1 = pop();
                value2 = pop();
                push((value2 % value1));
            }
            break;
        default:
            break;
        }
    }
}
