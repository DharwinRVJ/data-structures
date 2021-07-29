/*
The queue elements are 
->10->20->30->40
front =0, Rear=3
The deleted item is 10
The deleted item is 20
The queue elements are 
->30->40
front =2, Rear=3
The deleted item is 30
The deleted item is 40
front =-1, Rear=-1
*/
#include <stdio.h>
int que[10];
int size = 10;
int front = -1, rear = -1;

void enqueue(int);
void dequeue();
void display();

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    printf("\nfront =%d, Rear=%d", front, rear);
    dequeue();
    dequeue();
    display();
    printf("\nfront =%d, Rear=%d", front, rear);
    dequeue();
    dequeue();
    display();
    printf("\nfront =%d, Rear=%d", front, rear);
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
        rear = rear + 1;
        que[rear] = value;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty, cannot delete");
    }
    else
    {
        if (front == rear)
        {
            printf("\nThe deleted item is %d", que[front]);
            front = -1;
            rear = -1;
        }
        else
        {
            printf("\nThe deleted item is %d", que[front]);
            front = front + 1;
        }
    }
}
void display()
{
    int i;
    if (front >= 0)
    {
        printf("\nThe queue elements are \n");
        for (i = front; i <= rear; i++)
            printf("->%d", que[i]);
    }
}