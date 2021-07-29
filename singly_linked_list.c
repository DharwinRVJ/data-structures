/*
1,Creating linked list
->1->2->3
2,Insert 5 at front
->5->1->2->3
3,Insert 100 at 6th position
Check the position you entered
->5->1->2->3
4,Insert 0 at end
->5->1->2->3->0
5,Searching element 8
Element is not available
6,Searching element 100
Element is not available
7,Reversing the list
->0->3->2->1->5
8,Delete first element
Deleted data is 0
->3->2->1->5
9,Delete element at 4th position
Deleted data is 5
->3->2->1
10,Delete last element
Deleted data is 1
->3->2
No. of nodes: 2
Dharwin
*/
#include <stdlib.h>
#include <stdio.h>
void create();
void insfont(int);
void insmid(int, int);
void insend(int);
void search(int);
void reverse();
void dis();
void delfirst();
void delmid(int);
void dellast();
void dis();
int count();
struct node
{
    int data;
    struct node *next;
} * head, *mid, *last;
int main()
{
    printf("1,Creating linked list\n");
    create();
    dis();
    printf("2,Insert 5 at front\n");
    insfont(5);
    dis();
    printf("3,Insert 100 at 6th position\n");
    insmid(100, 6);
    dis();
    printf("4,Insert 0 at end\n");
    insend(0);
    dis();
    printf("5,Searching element 8\n");
    search(8);
    printf("6,Searching element 100\n");
    search(100);
    printf("7,Reversing the list\n");
    reverse();
    dis();
    printf("8,Delete first element\n");
    delfirst();
    dis();
    printf("9,Delete element at 4th position\n");
    delmid(4);
    dis();
    printf("10,Delete last element\n");
    dellast();
    dis();
    printf("No. of nodes: %d\n", count());
    printf("Dharwin");
    return 0;
}
void create()
{
    head = (struct node *)malloc(sizeof(struct node));
    mid = (struct node *)malloc(sizeof(struct node));
    last = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    mid->data = 2;
    last->data = 3;
    head->next = mid;
    mid->next = last;
    last->next = NULL;
}
int count()
{
    struct node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}
void insfont(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}
void insmid(int x, int pos)
{
    if (pos > 0 && pos <= count() + 1)
    {
        int i;
        struct node *temp, *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
        temp = head;
        if (pos == 1)
        {
            insfont(x);
            return;
        }
        if (pos == count() + 1)
        {
            insend(x);
            return;
        }
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        printf("Check the position you entered\n");
    }
}
void insend(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void search(int x)
{
    int i = 0, c = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        i++;
        if (temp->data == x)
        {
            c++;
            printf("Element is at position %d\n", i);
            break;
        }
        temp = temp->next;
    }
    if (c == 0)
    {
        printf("Element is not available\n");
    }
}
void reverse()
{
    struct node *curr = head, *prev = NULL, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void delfirst()
{
    struct node *todel = head;
    if (head == NULL)
    {
        printf("Empty list");
    }
    else
    {
        printf("Deleted data is %d\n", head->data);
        head = head->next;
        free(todel);
    }
}
void delmid(int pos)
{
    if (head == NULL)
    {
        printf("Empty list");
    }
    if (pos > 0 && pos <= count())
    {
        if (pos == 1)
        {
            delfirst();
            return;
        }
        if (pos == count())
        {
            dellast();
            return;
        }
        int i;
        struct node *todel, *prev;
        todel = head;
        prev = head;
        for (i = 1; i < pos; i++)
        {
            prev = todel;
            todel = todel->next;
        }

        prev->next = todel->next;
        free(todel);
    }
    else
    {
        printf("Check the position you entered\n");
    }
}
void dellast()
{
    int i;
    struct node *prev, *todel = head;
    if (head == NULL)
    {
        printf("Empty list");
    }
    else
    {
        while (todel->next != NULL)
        {
            prev = todel;
            todel = todel->next;
        }
        printf("Deleted data is %d\n", todel->data);
        prev->next = NULL;
        free(todel);
    }
}
void dis()
{
    struct node *dis = head;
    while (dis != NULL)
    {
        printf("->%d", dis->data);
        dis = dis->next;
    }
    printf("\n");
}
