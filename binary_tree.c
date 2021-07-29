/*
Preorder
1
2
4
3
5
6
Postorder
4
2
5
6
3
1
Inorder
2
4
1
5
3
6
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
} * root;
void preOrder(struct node *parent)
{
    if (parent)
    {
        printf("%d\n", parent->data);
        preOrder(parent->left);
        preOrder(parent->right);
    }
}
void postOrder(struct node *parent)
{
    if (parent)
    {
        postOrder(parent->left);
        postOrder(parent->right);
        printf("%d\n", parent->data);
    }
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
struct node *newNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main()
{
    int flag = 0;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    printf("Preorder\n");
    preOrder(root);
    printf("Postorder\n");
    postOrder(root);
    printf("Inorder\n");
    inOrder(root);
    return 0;
}