#include <stdio.h>
int calculateTotal(int marks[])
{
    int total = 0, i;
    for (i = 0; i < 5; i++)
    {
        total = total + marks[i];
    }

    return total;
}

float calculateAverage(int total)
{
    return total / 5.0;
}

void calculateGrade(float avg, char grade[], float *gpa)
{
    if (avg >= 80)
    {
        grade[0] = 'A';
        grade[1] = '+';
        grade[2] = '\0';
        *gpa = 4.00;
    }
    else if (avg >= 70)
    {
        grade[0] = 'A';
        grade[1] = '\0';
        *gpa = 3.50;
    }
    else if (avg >= 60)
    {
        grade[0] = 'A';
        grade[1] = '-';
        grade[2] = '\0';
        *gpa = 3.00;
    }
    else if (avg >= 50)
    {
        grade[0] = 'B';
        grade[1] = '\0';
        *gpa = 2.50;
    }
    else if (avg >= 40)
    {
        grade[0] = 'C';
        grade[1] = '\0';
        *gpa = 2.00;
    }
    else
    {
        grade[0] = 'F';
        grade[1] = '\0';
        *gpa = 0.00;
    }
}

void displayResult(char name[], int id, int total, float avg, char grade[], float gpa, int fail)
{
    printf("\n--- Student Result ---\n");
    printf("Name    : %s\n", name);
    printf("ID      : %d\n", id);
    printf("Total   : %d\n", total);
    printf("Average : %.2f\n", avg);
    printf("Grade   : %s\n", grade);
    printf("GPA     : %.2f\n", gpa);

    if (fail == 1)
        printf("Result  : Fail\n");
    else
        printf("Result  : Pass\n");
}

int main()
{
    char name[50], grade[5];
    int id, marks[5], i, total, fail = 0;
    float avg, gpa;

    printf("Enter student name: ");
    scanf(" %[^\n]", name);

    printf("Enter student ID: ");
    scanf("%d", &id);

    printf("Enter marks of 5 subjects: ");

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &marks[i]);

        if (marks[i] < 0 || marks[i] > 100)
        {
            printf("Invalid marks!\n");
            return 0;
        }

        if (marks[i] < 40)
            fail = 1;
    }

    total = calculateTotal(marks);
    avg = calculateAverage(total);

    calculateGrade(avg, grade, &gpa);

    if (fail == 1)
    {
        grade[0] = 'F';
        grade[1] = '\0';
        gpa = 0.00;
    }

    displayResult(name, id, total, avg, grade, gpa, fail);

    return 0;
}

