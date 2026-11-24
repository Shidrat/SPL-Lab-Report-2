#include <stdio.h>
struct Employee{
    int id;
    char name[30];
    float basic;
    float houseRent;
    float medical;
    float gross;
};

int main()
{
    struct Employee e[100];
    int n, i;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of employees!\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEmployee %d (ID name basic house-rent medical): ", i + 1);
        scanf("%d %29s %f %f %f",&e[i].id, e[i].name, &e[i].basic, &e[i].houseRent, &e[i].medical);

        e[i].gross = e[i].basic + e[i].houseRent + e[i].medical;
    }

    printf("\nID\tName\tBasic\t\tHouseRent\tMedical\t\tGross\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n", e[i].id, e[i].name, e[i].basic, e[i].houseRent, e[i].medical, e[i].gross);
    }

    return 0;
}
