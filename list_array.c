/*
list
list is empty
insert 10 at front
10 
insert 20 at front
20 10 
insert 30 at end
20 10 30 
insert 89 at end
20 10 30 89 
insert 11 at position - 7
Check the position you entered
20 10 30 89 
insert 43 at position - 5
20 10 30 89 43 
insert 21 at position - 3
20 10 21 30 89 43 
delete element at front
10 21 30 89 43 
delete element at end
10 21 30 89 
delete element at position - 7
check the position you entered
10 21 30 89 
delete element at position - 4
10 21 30 
delete element at position - 2
10 30 
*/
#include <stdio.h>
int arr[8];
int current = -1;
int isfull()
{
    if (current == 8)
        return 0;
    else
        return 0;
}
int isempty()
{
    if (current == -1)
        return 1;
    else
        return 0;
}
void display()
{
    if (isempty())
        puts("list is empty");
    else
    {
        for (int i = 0; i <= current; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}
void insertAtFront(int num)
{
    if (isfull())
        puts("list is full");
    else
    {
        for (int i = current; i >= 0; i--)
            arr[i + 1] = arr[i];
        arr[0] = num;
        ++current;
    }
}
void insertAtEnd(int num)
{
    if (isfull())
        puts("list is full");
    else
        arr[++current] = num;
}
void insertAtNth(int num, int pos)
{
    if (isfull())
        puts("list is full");
    else
    {
        if (pos >= 1 && pos <= (current + 2))
        {
            if (pos == 1)
                insertAtFront(num);
            else if (pos == current + 2)
                insertAtEnd(num);
            else
            {
                for (int i = current; i >= (pos - 1); i--)
                    arr[i + 1] = arr[i];
                arr[pos - 1] = num;
                ++current;
            }
        }
        else
            puts("Check the position you entered");
    }
}
void deleteAtFront()
{
    if (isempty())
        puts("list is empty");
    else
    {
        for (int i = 1; i <= current; i++)
            arr[i - 1] = arr[i];
        --current;
    }
}
void deleteAtEnd()
{
    if (isempty())
        puts("list is empty");
    else
        --current;
}
void deleteAtNth(int pos)
{
    if (isempty())
        puts("list is empty");
    else
    {
        if (pos >= 1 && pos <= (current + 1))
        {
            if (pos == 1)
                deleteAtFront();
            else if (pos == (current + 1))
                deleteAtEnd();
            else
            {
                for (int i = pos; i <= current; i++)
                    arr[i - 1] = arr[i];
                --current;
            }
        }
        else
            puts("check the position you entered");
    }
}
int main()
{
    puts("list");
    display();
    puts("insert 10 at front");
    insertAtFront(10);
    display();
    puts("insert 20 at front");
    insertAtFront(20);
    display();
    puts("insert 30 at end");
    insertAtEnd(30);
    display();
    puts("insert 89 at end");
    insertAtEnd(89);
    display();
    puts("insert 11 at position - 7");
    insertAtNth(11, 7);
    display();
    puts("insert 43 at position - 5");
    insertAtNth(43, 5);
    display();
    puts("insert 21 at position - 3");
    insertAtNth(21, 3);
    display();
    puts("delete element at front");
    deleteAtFront();
    display();
    puts("delete element at end");
    deleteAtEnd();
    display();
    puts("delete element at position - 7");
    deleteAtNth(7);
    display();
    puts("delete element at position - 4");
    deleteAtNth(4);
    display();
    puts("delete element at position - 2");
    deleteAtNth(2);
    display();
    return 0;
}