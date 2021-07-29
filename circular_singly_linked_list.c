/*
Enter no. of node:6
Enter the 1st value: 1
Enter 2 value: 43
Enter 3 value: 7
Enter 4 value: 32
Enter 5 value: 8
Enter 6 value: 9
->1->43->7->32->8->9
Inserting 100 at front
->100->1->43->7->32->8->9
Inserting 100 at last
->100->1->43->7->32->8->9->100
Enter the position to be insert: 3
Inserting 35 at pos 3
->100->1->35->43->7->32->8->9->100
Enter the no. to be searched: 101
The value is not present
Deleting at front
->1->35->43->7->32->8->9->100
Enter the position to be delete:20
Deleting value at 20 position
Check the position you entered
->1->35->43->7->32->8->9->100
Deleting at last
->1->35->43->7->32->8->9
Number of nodes is 7
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;

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
        }
        temp = head;
        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter %d value: ", i);
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            temp->next = newnode;
            temp = temp->next;
        }
        temp->next = head;
    }
}

void disp()
{
    struct node *temp = head;
    do
    {
        printf("->%d", temp->data);
        temp = temp->next;
    } while (temp != head);
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

void insertatfront(int d)
{
    struct node *newnode, *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newnode;
    head = newnode;
}
int insertatlast(int d)
{
    struct node *temp = head, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
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
        for (i = 1; i < pos - 1; i++)
            temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
        printf("Check the position you entered\n");
}
int dellast()
{
    struct node *temp = head, *pre;
    while (temp->next != head)
    {
        pre = temp;
        temp = temp->next;
    }
    pre->next = head;
    free(temp);
    return 0;
}
void delfront()
{
    struct node *temp = head, *nxt;
    nxt = temp->next;
    while (temp->next != head)
        temp = temp->next;
    temp->next = nxt;
    temp = head;
    head = head->next;
    free(temp);
}

void delatN(int pos, int n)
{
    int i;
    struct node *temp = head, *pre=head;
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
        for (i = 1; i < pos; i++)
        {
            pre = temp;
            temp = temp->next;
        }
        pre->next = temp->next;
        free(temp);
    }
    else printf("Check the position you entered\n");
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