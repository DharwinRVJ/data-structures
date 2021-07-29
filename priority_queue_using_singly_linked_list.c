/*
The Queue elements are
[23,12]  
The Queue elements are
[21,1]  [23,12]  
The Queue elements are
[21,1]  [53,2]  [23,12]  
The Queue elements are
[21,1]  [53,2]  [32,2]  [90,10]  [23,12]  
The deleted data item is 21 and its priority is 1
The Queue elements are
[53,2]  [32,2]  [90,10]  [23,12]  
The deleted data item is 53 and its priority is 2
The Queue elements are
[77,1]  [32,2]  [90,10]  [23,12]  
The deleted data item is 77 and its priority is 1
The Queue elements are
[32,2]  [90,10]  [23,12]
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
} * front;

void enqueue(int, int);
void dequeue();
void display();
int main()
{
    enqueue(23, 12);
    display();
    enqueue(21, 1);
    display();
    enqueue(53, 2);
    display();
    enqueue(32, 2);
    enqueue(90, 10);
    display();
    dequeue();
    display();
    dequeue();
    enqueue(77, 1);
    display();
    dequeue();
    display();
    return 0;
}
void enqueue(int value, int priority)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->priority = priority;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = newnode;
    }
    else
    {
        if (newnode->priority < front->priority)
        {
            newnode->next = front;
            front = newnode;
        }
        else
        {
            struct node *temp = front;
            while (temp->next->priority <= newnode->priority && temp->next != NULL)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}
void dequeue()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("\n Queue is empty \n");
    }
    else
    {
        printf("\nThe deleted data item is %d and its priority is %d", front->data, front->priority);
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
        printf("[%d,%d]  ", temp->data, temp->priority);
        temp = temp->next;
    }
}