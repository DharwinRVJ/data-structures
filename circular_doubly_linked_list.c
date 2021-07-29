/*
Enter no. of node:6
Enter the 1st value: 3
Enter 2 value: 6
Enter 3 value: 12
Enter 4 value: 78
Enter 5 value: 32
Enter 6 value: 23
->3->6->12->78->32->23
Inserting 100 at front
->100->3->6->12->78->32->23
Inserting 100 at last
->100->3->6->12->78->32->23->100
Enter the position to be insert: 3
Inserting 35 at pos 3
->100->3->35->6->12->78->32->23->100
Enter the no. to be searched: 6
The value is present at position 4
Deleting at front
->3->35->6->12->78->32->23->100
Enter the position to be delete:9
Deleting value at 9 position
Check the position you entered
->3->35->6->12->78->32->23->100
Deleting at last
->3->35->6->12->78->
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * head, *last;

void createnode(int n)
{
    struct node *newnode, *temp;
    int i;
    if (n >= 1)
    {
        if (head == NULL)
        {
            head = (struct node *)malloc(sizeof(struct node));
            printf("Enter the 1st value: ");
            scanf("%d", &head->data);
            head->next = NULL;
            head->prev = NULL;
        }
        last = head;
        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter %d value: ", i);
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
}
int counttotalnodes()
{
    struct node *temp = head;
    int c = 1;
    while (temp->next != head)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

void disp()
{
    int i;
    struct node *temp = head;
    for (i = 0; i < counttotalnodes(); i++)
    {
        printf("->%d", temp->data);
        temp = temp->next;
    }
}
void insertatfront(int d)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    last->next = head;
    head->prev = last;
}
int insertatlast(int d)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->prev = last;
    last->next = newnode;
    last = newnode;
    last->next = head;
    head->prev = last;
    return 0;
}
void insertatN(int d, int pos)
{
    struct node *temp = head, *newnode;
    int i;
    if (pos <= counttotalnodes() + 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = d;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (pos == 1)
        {
            insertatfront(d);
            return;
        }
        if (pos == counttotalnodes() + 1)
        {
            insertatlast(d);
            return;
        }

        for (i = 1; i < pos-1 ; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }
    else
        printf("Check the position you entered\n");
}

void delfront()
{
    struct node *temp = head, *nxt;
    head = temp->next;
    last->next = head;
    head->prev = last;
    free(temp);
}
int dellast()
{
    struct node *temp = last, *pre;
    last = temp->prev;
    last->next = head;
    head->prev = last;
    free(temp);
    return 0;
}

void delatN(int pos, int n)
{
    int i;
    struct node *temp = head, *pre;
    if (pos <= counttotalnodes())
    {
        if (pos == 1)
        {
            delfront();
            return;
        }
        if (pos == counttotalnodes())
        {
            dellast();
            return;
        }
        for (i = 0; i < pos; i++)
        {

            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    else
        printf("Check the position you entered\n");
}
void search(int key)
{
    struct node *temp = head;
    int flag = 0, i = 0;
    while (temp->next != head)
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

int main()
{
    int a, key, p;
    printf("Enter no. of node:");
    scanf("%d", &a);
    createnode(a);
    disp();
    printf("\nInserting 100 at front\n");
    insertatfront(100);
    disp();

    printf("\nInserting 100 at last\n");
    insertatlast(100);
    disp();

    printf("\nEnter the position to be insert: ");
    scanf("%d", &p);
    printf("Inserting 35 at pos %d\n", p);
    insertatN(35, p);
    disp();

    printf("\nEnter the no. to be searched: ");
    scanf("%d", &key);
    search(key);

    printf("\nDeleting at front\n");
    delfront();
    disp();

    printf("\nEnter the position to be delete:");
    scanf("%d", &p);
    printf("Deleting value at %d position\n", p);
    delatN(p, a);
    disp();

    printf("\nDeleting at last\n");
    dellast();
    disp();
    printf("\nNumber of nodes is %d", counttotalnodes());
}