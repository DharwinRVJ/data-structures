/*
enter no. of elements: 10
enter element - 1: 1
enter element - 2: 26
enter element - 3: 62
enter element - 4: 93
enter element - 5: 84
enter element - 6: 15
enter element - 7: 76
enter element - 8: 98
enter element - 9: 26
enter element - 10: 199
hash table
0               76
1               1
2               62
3               93
4               84
5               15
6               26
7               76
8               98
9               26
*/
#include <stdio.h>
#include <stdlib.h>
int *ptr;
unsigned int size, key;
unsigned int hash(int num)
{
    return (num % size);
}
void linearProbing(int num, unsigned int key)
{
    if (ptr[key] == -1)
        ptr[key] = num;
    else
    {
        for (int i = key + 1; i < size; i++)
            if (ptr[i] == -1)
            {
                ptr[i] = num;
                break;
            }
        for (int i = 0; i < key; i++)
            if (ptr[i] == -1)
            {
                ptr[i] = num;
                break;
            }
    }
}
int main(int argc, char *argv[])
{
    int num;
    printf("enter no. of elements: ");
    scanf("%u", &size);
    ptr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        ptr[i] = -1;
    for (int i = 0; i < size; i++)
    {
        printf("enter element - %d: ", i + 1);
        scanf("%d", &num);
        key = hash(num);
        linearProbing(num, key);
    }
    puts("hash table");
    for (int i = 0; i < size; i++)
        printf("%d\t\t%d\n", i, ptr[i]);
    return 0;
}
