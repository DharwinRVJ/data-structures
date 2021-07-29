/*
Entering 10, 20, 30 in the queue
The Queue elements are
->10->20->30
Front:10, rear:30
The deleted data item is 10
The Queue elements are
->20->30
Front:20, rear:30
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * front, *rear;

void enqueue(int);
void dequeue();
void display();
int main()
{
    printf("Entering 10, 20, 30 in the queue");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Front:%d, rear:%d", front->data, rear->data);
    dequeue();
    display();
    printf("Front:%d, rear:%d", front->data, rear->data);
    return 0;
}
void enqueue(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeue()
{
    struct node *temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nThe deleted data item is %d", front->data);
        front = front->next;
        free(temp);
    }
}
void display()
{
    struct node *temp = front;
    printf("\nThe Queue elements are\n");
    while (temp != NULL)
    {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}