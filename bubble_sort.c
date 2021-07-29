/*
-43 -12 -3 9 10 34 54 
*/
#include <stdio.h>
void swap(int *x, int *y)
{

    *x = (*x) + (*y);
    *y = (*x) - (*y);
    *x = (*x) - (*y);
}
int main(int argc, char *argv[])
{
    int size = 7;
    int arr[7] = {34, 54, -12, -3, 9, 0, -43};
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}