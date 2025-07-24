//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: light-weight
#include <stdio.h>

int main()
{
    float loanAmount, interestRate, monthlyInterestRate, monthlyPayment, principalPaid, interestPaid, balance;
    int numberOfYears, numberOfMonths, month;

    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);

    printf("Enter the interest rate: ");
    scanf("%f", &interestRate);

    printf("Enter the number of years: ");
    scanf("%d", &numberOfYears);

    numberOfMonths = numberOfYears * 12;
    monthlyInterestRate = interestRate / 1200;
    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - (1 / (pow(1 + monthlyInterestRate, numberOfMonths))));
    balance = loanAmount;

    printf("\nLoan Amount: $%.2f\n", loanAmount);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Number of Years: %d\n", numberOfYears);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);

    printf("\nPayment Schedule:\n");
    printf("%5s %12s %12s %12s %12s\n", "Month", "Balance", "Interest", "Principal", "Payment");

    for (month = 1; month <= numberOfMonths; month++)
    {
        interestPaid = balance * monthlyInterestRate;
        principalPaid = monthlyPayment - interestPaid;
        balance = balance - principalPaid;

        printf("%5d %12.2f %12.2f %12.2f %12.2f\n", month, balance, interestPaid, principalPaid, monthlyPayment);
    }

    return 0;
}