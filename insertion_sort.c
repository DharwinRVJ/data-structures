/*
-43 -12 -3 9 10 34 54 
*/
#include <stdio.h>
int main(int argc, char *argv[])
{
    int size = 7;
    int arr[7] = {34, 54, -12, -3, 9, 10, -43};
    for (int i = 1; i < size; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[++j] = key;
    }
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}