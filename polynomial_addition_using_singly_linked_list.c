/*
Create polynomial1
Enter the coeff:4
Enter the exponent:2
whether to continue(1/0)1
Enter the coeff:4
Enter the exponent:1
whether to continue(1/0)1
Enter the coeff:4
Enter the exponent:0
whether to continue(1/0)0
Create polynomial2
Enter the coeff:2
Enter the exponent:2
whether to continue(1/0)1
Enter the coeff:1
Enter the exponent:0
whether to continue(1/0)0
Displaying polynomials
poly1
+4X2+4X1+4X0
poly2
+2X2+1X0
Adding
+6X2+4X1+5X0
*/
#include <stdio.h>
#include <stdlib.h>
struct polynode
{
    int coeff;
    int exp;
    struct polynode *next;
} * p1head, *p2head, *p3head;
struct polynode *createpoly();
void display(struct polynode *);
struct polynode *addpoly();
int main()
{
    printf("Create polynomial1\n");
    p1head = createpoly();
    printf("Create polynomial2\n");
    p2head = createpoly();
    printf("Displaying polynomials\n");
    printf("poly1\n");
    display(p1head);
    printf("\npoly2\n");
    display(p2head);
    printf("\nAdding\n");
    p3head = addpoly();
    display(p3head);
    return 0;
}
struct polynode *createpoly()
{
    struct polynode *newnode, *phead, *last;
    int ch = 1;
    phead = NULL;

    while (ch == 1)
    {
        newnode = (struct polynode *)malloc(sizeof(struct polynode));
        printf("Enter the coeff:");
        scanf("%d", &newnode->coeff);
        printf("Enter the exponent:");
        scanf("%d", &newnode->exp);
        newnode->next = NULL;
        if (phead == NULL)
        {
            phead = newnode;
            last = phead;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }
        printf("whether to continue(1/0)");
        scanf("%d", &ch);
    }
    return phead;
}
void display(struct polynode *p)
{
    struct polynode *temp = p;
    while (temp != NULL)
    {
        printf("+%dX%d", temp->coeff, temp->exp);
        temp = temp->next;
    }
}
struct polynode *addpoly()
{
    struct polynode *temp1, *temp2, *temp3, *newnode, *phead;
    temp1 = p1head;
    temp2 = p2head;
    phead = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        newnode = (struct polynode *)malloc(sizeof(struct polynode));
        if (temp1->exp == temp2->exp)
        {
            newnode->coeff = temp1->coeff + temp2->coeff;
            newnode->exp = temp1->exp;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp < temp2->exp)
        {
            newnode->coeff = temp2->coeff;
            newnode->exp = temp2->exp;

            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            newnode->coeff = temp1->coeff;
            newnode->exp = temp1->exp;

            temp1 = temp1->next;
        }
        newnode->next = NULL;
        if (phead == NULL)
        {
            phead = newnode;
            temp3 = phead;
        }
        else
        {
            temp3->next = newnode;
            temp3 = newnode;
        }
    }
    while (temp1 != NULL)
    {
        newnode = (struct polynode *)malloc(sizeof(struct polynode));
        newnode->coeff = temp1->coeff;
        newnode->exp = temp1->exp;
        newnode->next = NULL;
        temp3->next = newnode;
        temp3 = newnode;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        newnode = (struct polynode *)malloc(sizeof(struct polynode));
        newnode->coeff = temp2->coeff;
        newnode->exp = temp2->exp;
        newnode->next = NULL;
        temp3->next = newnode;
        temp3 = newnode;
        temp2 = temp2->next;
    }
    return phead;
}