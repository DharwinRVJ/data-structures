/*
-23 -12 0 0 7 9 10 23 34 101 
*/
#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int beg, int end, int a[])
{
    int pivot = a[end], partitionIn = beg;
    for (int j = beg; j < end; j++)
        if (a[j] <= pivot)
        {
            swap(&a[j], &a[partitionIn]);
            ++partitionIn;
        }
    swap(&a[partitionIn], &a[end]);
    return (partitionIn);
}
void quickSort(int beg, int end, int a[])
{
    if (beg < end)
    {
        int pi = partition(beg, end, a);
        quickSort(beg, pi - 1, a);
        quickSort(pi + 1, end, a);
    }
}
int main()
{
    int a[10] = {10, 9, 7, 101, -23, 0, -12, 0, 34, 23};
    int i;
    quickSort(0, 9, a);
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return 0;
}
