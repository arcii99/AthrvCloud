//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: optimized
#include <stdio.h>
#include <math.h>

int main()
{
    double loanAmount, monthlyInterestRate, monthlyPayment, balance;
    int months, i;

    printf("Enter the loan amount: ");
    scanf("%lf", &loanAmount);
    printf("Enter the monthly interest rate: ");
    scanf("%lf", &monthlyInterestRate);
    printf("Enter the number of months: ");
    scanf("%d", &months);

    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -months));

    printf("Monthly Payment: $%.2lf\n", monthlyPayment);

    balance = loanAmount;

    printf("\n");

    printf("Month\tPayment\t\tInterest\tBalance\n");

    for (i = 1; i <= months; i++)
    {
        double interest = monthlyInterestRate * balance;
        balance -= (monthlyPayment - interest);

        printf("%d\t$%.2lf\t\t$%.2lf\t\t$%.2lf\n", i, monthlyPayment, interest, balance);
    }

    return 0;
}