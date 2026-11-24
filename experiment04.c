#include <stdio.h>
int checkBalance(float balance, float amount)
{
    if (balance >= amount)
        return 1;
    else
        return 0;
}

int validateWithdrawal(float amount)
{
    if (amount > 0 && amount == (int)amount)
    {
        if ((int)amount % 500 == 0)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

float withdrawMoney(float balance, float amount)
{
    return balance - amount;
}

void displayTransaction(float amount, float balance, int status)
{
    if (status == 1)
    {
        printf("\nTransaction Status : Successful\n");
        printf("Amount Withdrawn : Tk %.2f\n", amount);
        printf("Remaining Balance: Tk %.2f\n", balance);
    }
    else
    {
        printf("\nTransaction Failed!\n");
        printf("Remaining Balance: Tk %.2f\n", balance);
    }
}

int main()
{
    float balance, amount;
    int status = 0;

    printf("Enter account balance: ");
    scanf("%f", &balance);

    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (balance < 0)
    {
        printf("Invalid balance!\n");
        return 0;
    }

    if (validateWithdrawal(amount) == 1)
    {
        if (checkBalance(balance, amount) == 1)
        {
            balance = withdrawMoney(balance, amount);
            status = 1;
        }
    }

    displayTransaction(amount, balance, status);

    return 0;
}
