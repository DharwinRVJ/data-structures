#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *pre;
} * head, *last;
void disp()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void interchange()
{
    int i, temp3;
    struct node *temp1 = head, *temp2 = last;
    for (i = 1; i <= 2; i++)
    {
        temp3 = temp1->data;
        temp1->data = temp2->data;
        temp2->data = temp3;
        temp1 = temp1->next;
        temp2 = temp2->pre;
    }
}
void create()
{
    int i;
    struct node *newnode;
    head = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &head->data);
    head->next = NULL;
    head->pre = NULL;
    last = head;
    for (i = 2; i <= 5; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->pre = last;
        last->next = newnode;
        last = newnode;
    }

    newnode = last;
}
int main()
{
    create();
    interchange();
    disp();
    return 0;
}
