#include <stdio.h>
int que[5];
int size = 5;
int front = -1, rear = -1;
void enqueue(int);
void display();
int main()
{
    int i, data;
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &data);
        enqueue(data);
    }
    display();
    return 0;
}
void enqueue(int value)
{
    if (rear == size - 1)
    {
        printf("\n Queue is full, cannot insert");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        que[rear] = value;
    }
}
void display()
{
    int i;
    for (i = rear; i >= front; i--)
        printf("%d ", que[i]);
}