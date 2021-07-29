/*
enter the no. of elements : 2
enter the elements : 
enter the element - 1 : 23
enter the element - 2 : 32
enter the value to search : 10
10 is not present in that array
*/
/*
enter the no. of elements : 5
enter the elements : 
enter the element - 1 : 1
enter the element - 2 : 34
enter the element - 3 : 56
enter the element - 4 : 76
enter the element - 5 : 89
enter the value to search : 34
34 is present in the array
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    unsigned int i1;
    int *ptr, search, beg = 0, end, mid;
    printf("enter the no. of elements : ");
    scanf("%u", &i1);
    end = i1 - 1;
    ptr = (int *)malloc(i1 * sizeof(int));
    puts("enter the elements : ");
    for (int i = 0; i < i1; i++)
    {
        printf("enter the element - %d : ", i + 1);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < i1; i++)
    {
        for (int j = i + 1; j < i1; j++)
        {
            if (ptr[i] > ptr[j])
            {
                ptr[i] = ptr[i] + ptr[j];
                ptr[j] = ptr[i] - ptr[j];
                ptr[i] = ptr[i] - ptr[j];
            }
        }
    }
    printf("enter the value to search : ");
    scanf("%d", &search);
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (ptr[mid] == search)
        {
            printf("%d is present in the array", ptr[mid]);
            return 0;
        }
        else if (ptr[mid] > search)
            end = mid - 1;
        else if (ptr[mid] < search)
            beg = mid + 1;
    }
    printf("%d is not present in that array", search);
    return 0;
}