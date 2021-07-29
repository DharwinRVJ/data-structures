/*
Inorder
1
3
4
6
7
8
10
14

Element is not present
Element is present
Inorder
1
3
4
8
10
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
} * root;
struct node *insertNode(struct node *parent, int val)
{
    if (parent == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if (val < parent->data)
        parent->left = insertNode(parent->left, val);
    if (val > parent->data)
        parent->right = insertNode(parent->right, val);
    return parent;
}
void searchNode(struct node *parent, int val)
{
    if (parent)
    {
        if (parent->data == val)
        {
            printf("\nElement is present");
            return;
        }
        if (val < parent->data)
            return searchNode(parent->left, val);
        if (val > parent->data)
            return searchNode(parent->right, val);
    }
    else
        printf("\nElement is not present");
}
struct node *minValNode(struct node *parent)
{
    struct node *current = parent;
    while (current->left != NULL)
        current = current->left;
    return current;
}
struct node *delNode(struct node *parent, int val)
{
    if (parent == NULL)
        return parent;
    if (val < parent->data)
        parent->left = delNode(parent->left, val);
    else if (val > parent->data)
        parent->right = delNode(parent->right, val);
    else
    {
        if (parent->left == NULL)
        {
            struct node *temp = parent->right;
            free(parent);
            return temp;
        }
        else if (parent->right == NULL)
        {
            struct node *temp = parent->left;
            free(parent);
            return temp;
        }
        struct node *temp = minValNode(parent->right);
        parent->data = temp->data;
        parent->right = delNode(parent->right, temp->data);
    }
    return parent;
}
void inOrder(struct node *parent)
{
    if (parent)
    {
        inOrder(parent->left);
        printf("%d\n", parent->data);
        inOrder(parent->right);
    }
}
int main()
{
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 7);
    root = insertNode(root, 10);
    root = insertNode(root, 14);
    root = insertNode(root, 4);
    printf("Inorder\n");
    inOrder(root);
    searchNode(root, 30);
    searchNode(root, 14);
    root = delNode(root, 6);
    root = delNode(root, 7);
    root = delNode(root, 14);
    printf("\nInorder\n");
    inOrder(root);
    return 0;
}