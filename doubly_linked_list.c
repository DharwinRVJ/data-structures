/*
Enter no. of nodes: 5
Enter data for node 1: 21
Enter data for node 2: 22
Enter data for node 3: 5
Enter data for node 4: 7
Enter data for node 5: 15
->21->22->5->7->15
Inserting 100 at front:
->100->21->22->5->7->15
Inserting 500 at last:
->100->21->22->5->7->15->500
Enter the position: 3
Inserting 200 at position-3:
->100->21->200->22->5->7->15->500
Deleting first data:
->21->200->22->5->7->15->500
Deleting last data:
->21->200->22->5->7->15
Enter the position to be deleted:2
Deleting position-2: ->21->22->5->7->15
Number of nodes is 5
Enter the value to be search: 5
Searching for 5
The value is present at position 3
Printing in reverse order:
->15->7->5->22->21
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *pre;
} * head, *last;

void createlist(int n)
{
    int i;
    struct node *newnode;
    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node 1: ");
        scanf("%d", &head->data);
        head->next = NULL;
        head->pre = NULL;
        last = head;
        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data for node %d: ", i);
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            newnode->pre = last;
            last->next = newnode;
            last = newnode;
        }
    }
    newnode = last;
}

void disp()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
        printf("\nlist is empty");
    else
    {
        while (temp != NULL)
        {
            printf("->%d", temp->data);
            temp = temp->next;
        }
    }
}

void insertatfront(int data)
{
    struct node *newnode, *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->pre = NULL;
    newnode->data = data;
    newnode->next = temp;
    temp->pre = newnode;
    head = newnode;
}

void insertatlast(int data)
{
    struct node *newnode, *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->pre = temp;
    temp->next = newnode;
}

void delfirst()
{
    struct node *temp = head;
    head = temp->next;
    head->pre = NULL;
    free(temp);
}

void dellast()
{
    struct node *temppre = head, *tempnext = head;
    while (tempnext->next != NULL)
    {
        temppre = tempnext;
        tempnext = tempnext->next;
    }
    temppre->next = NULL;
    free(tempnext);
}

int counttotalnodes()
{
    struct node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

void search(int key)
{
    struct node *temp = head;
    int flag = 0, i = 0;
    while (temp->next != NULL)
    {
        i++;
        if (key == temp->data)
        {
            printf("The value is present at position %d", i);
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0)
        printf("The value is not present");
}

void insertatn(int data, int pos)
{
    struct node *temp = head;
    struct node *newnode;
    int i;
    if (pos <= counttotalnodes() + 1)
    {
        if (pos == 1)
        {
            insertatfront(data);
            return;
        }
        if (pos == counttotalnodes() + 1)
        {
            insertatlast(data);
            return;
        }

        for (i = 1; i < pos - 1 && temp != NULL; i++)
        {

            temp = temp->next;
        }

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = temp->next;
        newnode->pre = temp;
        if (temp->next != NULL)
            temp->next->pre = newnode;
        temp->next = newnode;
    }
    else
        printf("Check the position you entered\n");
}

void deleteN(int pos)
{
    struct node *temp = head;
    int i;
    if (pos <= counttotalnodes())
    {
        if (pos == 1)
        {
            delfirst();
            return;
        }
        if (pos == counttotalnodes())
        {
            dellast();
            return;
        }
        for (i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        free(temp);
    }
    else
        printf("\nCheck the position you entered\n");
}

void traversefromlast()
{
    struct node *temp = last;
    printf("\nPrinting in reverse order:\n");
    while (temp != NULL)
    {
        printf("->%d", temp->data);
        temp = temp->pre;
    }
}

int main()
{
    int a, k, n;
    printf("Enter no. of nodes: ");
    scanf("%d", &a);
    createlist(a);
    disp();

    printf("\nInserting 100 at front:\n");
    insertatfront(100);
    disp();

    printf("\nInserting 500 at last:\n");
    insertatlast(500);
    disp();

    printf("\nEnter the position: ");
    scanf("%d", &n);
    printf("Inserting 200 at position-%d:\n", n);
    insertatn(200, n);
    disp();

    printf("\nDeleting first data:\n");
    delfirst();
    disp();

    printf("\nDeleting last data:\n");
    dellast();
    disp();

    printf("\nEnter the position to be deleted:");
    scanf("%d", &n);
    printf("Deleting position-%d: ", n);
    deleteN(n);
    disp();
    printf("\nNumber of nodes is %d", counttotalnodes());

    printf("\nEnter the value to be search: ");
    scanf("%d", &k);
    printf("Searching for %d\n", k);
    search(k);

    traversefromlast();

    return 0;
}
