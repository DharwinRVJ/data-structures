/*
Enter the infix string: (a+b*c)/d%e
The postfix expression is abc*+d/e%
*/
#include <stdio.h>
#include <string.h>
int stack[20], top = -1, MAX = 20;
char infixstr[20], postfixstr[20];
int isfull();
int isempty();
int peek();
void push(int);
int pop();
void display();
int precedence(char);
void infixtopostfix();

int main()
{
    printf("Enter the infix string: ");
    scanf("%s", infixstr);
    infixtopostfix();
    printf("The postfix expression is %s", postfixstr);
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
int pop()
{
    int data;
    if (isempty())
        printf("\nstack is empty, cannot remove\n");
    else
    {
        data = stack[top];
        //printf("\nThe popped element is %d\n",stack[top]);
        top--;
    }
    return data;
}
void display()
{
    int i;
    printf("\ndisplaying stack elements\n");
    for (i = 0; i <= top; i++)
        printf("%d-", stack[i]);
}
int peek()
{
    return stack[top];
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    default:
        return 0;
    }
}

void infixtopostfix()
{
    int i, temp = 0;
    char symbol, next;
    for (i = 0; i < strlen(infixstr); i++)
    {
        symbol = infixstr[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next = pop()) != '(')
            {
                postfixstr[temp++] = next;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            while (!isempty() && precedence(stack[top]) >= precedence(symbol))
                postfixstr[temp++] = pop();
            push(symbol);
            break;
        default:
            postfixstr[temp++] = symbol;
        }
    }
    while (!isempty())
        postfixstr[temp++] = pop();
}