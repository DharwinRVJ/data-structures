#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head;
void count()
{
    struct node *temp = head;
    int value = 0, count = 0;
    scanf("%d", &value);
    while (temp != NULL)
    {
        if (temp->data == value)
            count++;
        temp = temp->next;
    }
    printf("%d", count);
}
void create()
{
    struct node *newnode, *temp;
    int i;
    for (i = 1; i <= 5; i++)
    {
        if (i == 1)
        {
            head = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &head->data);
            head->next = NULL;
            temp = head;
        }
        else
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            temp->next = newnode;
            temp = temp->next;
        }
    }
}
int main()
{
    create();
    count();
    return 0;
}