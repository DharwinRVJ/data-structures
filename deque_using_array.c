/*
Queue is empty

The Queue elements are
->82
The Queue elements are
->12->82
The Queue elements are
->12->82->90
The Queue elements are
->18->12->82->90
The Queue elements are
->18->12->82->90->21
The deleted element is 18
The Queue elements are
->12->82->90->21
The deleted element is 12
The Queue elements are
->82->90->21
*/
#include <stdio.h>
int size = 5;
int deck[5];
int front = -1, rear = -1;

void insertrear(int);
void insertfront(int);
void deleterear();
void deletefront();
void display();
int main()
{
    display();
    insertfront(82);
    display();
    insertfront(12);
    display();
    insertrear(90);
    display();
    insertfront(18);
    display();
    insertrear(21);
    display();
    deletefront();
    display();
    deletefront();
    display();
    return 0;
}
void insertrear(int value)
{
    if ((front == 0 && rear == size - 1) || front == rear + 1)
        printf("\nQueue is full, cannot insert");
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }

        if (rear == size - 1)
            rear = 0;
        else
            rear++;
        deck[rear] = value;
    }
}
void insertfront(int value)
{
    if ((rear == size - 1 && front == 0) || (front == rear + 1))
    {
        printf("\nQueue is full, cannot insert");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            if (front == 0)
                front = size - 1;
            else
            {
                front--;
            }
        }
        deck[front] = value;
    }
}
void deleterear()
{
    int data;
    if (front == -1 && rear == -1)
        printf("\nqueue is empty, cannot delete");
    else
    {
        data = deck[rear];
        printf("\nThe deleted element is %d", data);
        if (front == rear)
            front = rear = -1;

        else if (rear == size - 1)
            rear--;
        else
            rear = rear - 1;
    }
}
void deletefront()
{
    int data;
    if (front == -1 && rear == -1)
        printf("\nqueue is empty, cannot delete");
    else
    {
        data = deck[front];
        printf("\nThe deleted element is %d", data);
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
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nThe Queue elements are\n");
        i = front;
        if (front <= rear)
        {
            while (i <= rear)
            {
                printf("->%d", deck[i]);
                i++;
            }
        }
        else
        {
            while (i <= size - 1)
            {
                printf("->%d", deck[i]);
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                printf("->%d", deck[i]);
                i++;
            }
        }
    }
}