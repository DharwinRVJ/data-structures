#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * head, *last;
void disp()
{
    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void interchange()
{
    int position = 0, i, k, k1;
    scanf("%d", &position);
    struct node *temp = head;
    for (i = 1; i < position; i++)
    {
        temp = temp->next;
    }
    k = temp->data;
    k1 = temp->next->data;
    temp->data = k1;
    temp->next->data = k;
}
void create()
{
    struct node *newnode;
    int i;
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &head->data);
        head->next = NULL;
        head->prev = NULL;
        last = head;
    }
    for (i = 2; i <= 5; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        last->next = newnode;
        newnode->prev = last;
        last = last->next;
    }
    last->next = head;
    head->prev = last;
}
int main()
{
    create();
    interchange();
    disp();
    return 0;
}
