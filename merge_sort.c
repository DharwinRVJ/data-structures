/*
-23 -12 0 7 9 10 23 34 44 101 
*/
#include <stdio.h>
void merge(int beg, int end, int a[], int mid)
{
    int i = beg, j = mid + 1, k, index = beg;
    int temp[10];
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
            temp[index++] = a[i++];
        else
            temp[index++] = a[j++];
    }
    while (i <= mid)
        temp[index++] = a[i++];
    while (j <= end)
        temp[index++] = a[j++];
    k = beg;
    while (k < index)
    {
        a[k] = temp[k];
        k++;
    }
}
void mergeSort(int beg, int end, int a[])
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(beg, mid, a);
        mergeSort(mid + 1, end, a);
        merge(beg, end, a, mid);
    }
}
int main()
{
    int a[10] = {10, 9, 7, 101, -23, 44, -12, 0, 34, 23};
    int i;
    mergeSort(0, 9, a);
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return 0;
}
