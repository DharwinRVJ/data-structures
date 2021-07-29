/*
Enter no. of Soldiers:10
The position to choose is 5
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;
void joshepous()
{
    struct node *todel = head, *temp = head;
    while (temp->next != temp)
    {
        todel = temp->next;
        temp->next = todel->next;
        free(todel);
        temp = temp->next;
    }
    printf("The position to choose is %d", temp->data);
}
void createnode(int n)
{
    struct node *newnode, *temp;
    int i;
    if (n >= 1)
    {
        if (head == NULL)
        {
            head = (struct node *)malloc(sizeof(struct node));
            head->data = 1;
            head->next = NULL;
        }
        temp = head;
        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = i;
            newnode->next = NULL;
            temp->next = newnode;
            temp = temp->next;
        }
        temp->next = head;
    }
}

int main()
{
    int a;

    printf("Enter no. of Soldiers:");
    scanf("%d", &a);
    createnode(a);
    joshepous();
    return 0;
}
