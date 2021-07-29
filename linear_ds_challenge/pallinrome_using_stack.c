#include <stdio.h>
#include <string.h>
char stack[20];
int top = -1, MAX = 20;
char c[20];
int isfull();
int isempty();
void push(char);
char pop();
int main()
{
    scanf("%s", c);
    int i, flag = 0;
    for (i = 0; i < strlen(c); i++)
        push(c[i]);
    for (i = 0; i < strlen(c); i++)
    {
        if (c[i] == pop())
            flag = 1;
        else
            flag = -1;
    }
    if (flag == 1)
        printf("It is palindrome");
    else
        printf("It is not palindrome");
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
void push(char x)
{
    if (isfull())
        printf("\nStack is full\n");
    else
    {
        top++;
        stack[top] = x;
    }
}
char pop()
{
    char data;
    data = stack[top];
    top--;
    return data;
}
