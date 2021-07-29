/*
Entering 10,20,30,40,50 in the queue
The Queue elements are
->10->20->30->40->50
Front=0  Rear=4
The deleted element is 10
The deleted element is 20
The Queue elements are
->30->40->50
Front=2  Rear=4
The Queue elements are
->30->40->50->60->70
Front=2  Rear=1
*/
#include <stdio.h>
int size = 5;
int cqueue[5];
int front = -1, rear = -1;

void enqueue(int);
void dequeue();
void display();
int main()
{
    printf("Entering 10,20,30,40,50 in the queue\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    printf("\nFront=%d  Rear=%d\n", front, rear);
    dequeue();
    dequeue();
    display();
    printf("\nFront=%d  Rear=%d\n", front, rear);
    enqueue(60);
    enqueue(70);
    display();
    printf("\nFront=%d  Rear=%d\n", front, rear);
    return 0;
}
void enqueue(int value)
{
    if ((front == 0 && rear == size - 1) || front == rear + 1)
        printf("\n Queue is full, cannot insert\n");
    else
    {
        if (front == -1 && rear == -1)
            front = 0;
        if (rear == size - 1 && front != 0)
            rear = -1;
        rear = rear + 1;
        cqueue[rear] = value;
    }
}
void dequeue()
{
    int data;
    if (front == -1 && rear == -1)
        printf("\nqueue is empty, cannot delete\n");
    else
    {
        data = cqueue[front];
        printf("The deleted element is %d\n", data);
        if (front == rear)
            front = rear = -1;

        else if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }
}
void display()
{
    int i;
    if (front == -1 && rear == -1)
        printf("\nQueue is empty\n");
    else
    {
        printf("The Queue elements are\n");
        i = front;
        if (front <= rear)
        {
            while (i <= rear)
            {
                printf("->%d", cqueue[i]);
                i++;
            }
        }
        else
        {
            while (i <= size - 1)
            {
                printf("->%d", cqueue[i]);
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                printf("->%d", cqueue[i]);
                i++;
            }
        }
    }
}