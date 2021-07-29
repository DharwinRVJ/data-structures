/*
Enter the number of students:3
Enter the details of student - 1
Name: ram
Roll no.: 101
Enter subject 1 mark out of 100: 90
Enter subject 2 mark out of 100: 98
Enter subject 3 mark out of 100: 100
Enter the details of student - 2
Name: raj
Roll no.: 102
Enter subject 1 mark out of 100: 89
Enter subject 2 mark out of 100: 32
Enter subject 3 mark out of 100: 77
Enter the details of student - 3
Name: raghu
Roll no.: 103
Enter subject 1 mark out of 100: 33
Enter subject 2 mark out of 100: 22
Enter subject 3 mark out of 100: 10

Details

Details of student - 1
Name: ram
Roll: 101
Subject - 1: 90
Subject - 2: 98
Subject - 3: 100
Grade: A+ grade 
Total: 288
Details of student - 2
Name: raj
Roll: 102
Subject - 1: 89
Subject - 2: 32
Subject - 3: 77
Grade: NIL-You failed in some subjects
Total: 198
Details of student - 3
Name: raghu
Roll: 103
Subject - 1: 33
Subject - 2: 22
Subject - 3: 10
Grade: NIL-You failed in some subjects
Total: 65
Average and class average:
Name    Average
ram     96.000000
raj     66.000000
raghu   21.000000
Class average: 61.000000

Students who got average less than 40% :
raghu
*/
#include <stdio.h>
#include <string.h>
void fun1();
void fun2();
void fun3();
int n;
struct student
{
    char name[25];
    int roll;
    int marks[3];
    int tot;
    float avg;
} stud[100];
int main()
{
    int i, j;
    printf("Enter the number of students:");
    scanf("%d", &n);
    if (n > 0 && n < 101)
    {
        for (i = 0; i < n; i++)
        {
            printf("Enter the details of student - %d\n", i + 1);
            printf("Name: ");
            fflush(stdin);
            scanf("%s", stud[i].name);
            printf("Roll no.: ");
            scanf("%d", &stud[i].roll);
            stud[i].tot = 0;
            for (j = 0; j < 3; j++)
            {
                printf("Enter subject %d mark out of 100: ", j + 1);
                scanf("%d", &stud[i].marks[j]);
                stud[i].tot = stud[i].tot + stud[i].marks[j];
            }
            stud[i].avg = stud[i].tot / 3;
        }
        fun1();
    }
    else
    {
        printf("Invaild number");
    }
    return 0;
}
void fun1()
{
    int i, g, j;
    printf("\nDetails\n");
    for (i = 0; i < n; i++)
    {
        printf("\nDetails of student - %d\n", i + 1);
        printf("Name: %s\n", stud[i].name);
        printf("Roll: %d\n", stud[i].roll);
        g = 0;
        for (j = 0; j < 3; j++)
        {
            printf("Subject - %d: %d\n", j + 1, stud[i].marks[j]);
            if (stud[i].marks[j] > 35)
            {
                g++;
            }
        }
        if (g == 3)
        {
            if (stud[i].tot > 250 && stud[i].tot <= 300)
            {
                printf("Grade: A+ grade ");
            }
            else if (stud[i].tot > 200 && stud[i].tot <= 250)
            {
                printf("Grade: A grade ");
            }
            else if (stud[i].tot > 150 && stud[i].tot <= 200)
            {
                printf("Grade: B+ grade ");
            }
            else if (stud[i].tot > 100 && stud[i].tot <= 150)
            {
                printf("Grade: B grade ");
            }
            else
            {
                printf("Grade: C+ grade ");
            }
        }
        else
        {
            printf("Grade: NIL-You failed in some subjects");
        }
        printf("\nTotal: %d", stud[i].tot);
    }
    fun2();
}

void fun2()
{
    int i;
    float classavg = 0.0;
    printf("\nAverage and class average:\n");
    printf("Name\tAverage\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t%f\n", stud[i].name, stud[i].avg);
        classavg = classavg + stud[i].avg;
    }
    printf("Class average: %f", classavg / n);
    fun3();
}
void fun3()
{
    int i, a = 0;
    printf("\n\nStudents who got average less than 40%% :\n");
    for (i = 0; i < n; i++)
    {
        if (stud[i].avg < 40)
        {
            printf("%s\n", stud[i].name);
            a++;
        }
    }
    if (a == 0)
    {
        printf("-NIL-");
    }
}
