/*
priority Queue: 7 7 11 12 14 31 20 13 45 
node with minimum priority: 7
priority queue after extracting minimum: 7 12 11 13 14 31 20 45 
changing priority of index 2 to 49
priority queue after changing priority: 7 12 20 13 14 31 49 45 
removing element at index 3
priority queue after removing the element: 7 12 20 45 14 31 49 
heap sort: 7 12 14 20 31 45 49
*/
#include <stdio.h>
int H[50];
int size = -1;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int parent(int i)
{
    return (i / 2);
}
int leftChild(int i)
{
    return ((2 * i) + 1);
}
int rightChild(int i)
{
    return ((2 * i) + 2);
}
void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] > H[i])
    {
        swap(&H[parent(i)], &H[i]);
        i = parent(i);
    }
}
void shiftDown(int i)
{
    int minIndex = i;
    int l = leftChild(i);
    if (l <= size && H[l] < H[minIndex])
        minIndex = l;
    int r = rightChild(i);
    if (r <= size && H[r] < H[minIndex])
        minIndex = r;
    if (i != minIndex)
    {
        swap(&H[i], &H[minIndex]);
        shiftDown(minIndex);
    }
}
void insert(int p)
{
    ++size;
    H[size] = p;
    shiftUp(size);
}
int extractMin()
{
    int result = H[0];
    H[0] = H[size];
    --size;
    shiftDown(0);
    return result;
}
void changePriority(int i, int newp)
{
    int oldp = H[i];
    H[i] = newp;
    if (newp > oldp)
        shiftDown(i);
    else
        shiftUp(i);
}
int getMin()
{
    return H[0];
}
void reMove(int i)
{
    H[i] = getMin();
    shiftUp(i);
    extractMin();
}
int main()
{
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);
    int i = 0;
    printf("priority Queue: ");
    while (i <= size)
        printf("%d ", H[i++]);
    printf("\n");
    printf("node with minimum priority: %d\n", getMin());
    extractMin();
    printf("priority queue after extracting minimum: ");
    i = 0;
    while (i <= size)
        printf("%d ", H[i++]);
    printf("\n");
    changePriority(2, 49);
    puts("changing priority of index 2 to 49");
    printf("priority queue after changing priority: ");
    i = 0;
    while (i <= size)
        printf("%d ", H[i++]);
    printf("\n");
    puts("removing element at index 3");
    reMove(3);
    printf("priority queue after removing the element: ");
    i = 0;
    while (i <= size)
        printf("%d ", H[i++]);
    printf("\n");
    printf("heap sort: ");
    while (size != -1)
        printf("%d ", extractMin());
    return 0;
}