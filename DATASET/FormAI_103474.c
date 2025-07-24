//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: grateful
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Welcome to the Mortgage Calculator by Grateful Bot!\n");
    printf("Please enter the loan amount (in dollars): ");
    double loanAmount;
    scanf("%lf", &loanAmount);

    printf("Please enter the interest rate (in percentage per year): ");
    double interestRate;
    scanf("%lf", &interestRate);
    double monthlyInterestRate = interestRate / 12 / 100;

    printf("Please enter the duration of the loan (in years): ");
    double loanDuration;
    scanf("%lf", &loanDuration);
    double numberOfPayments = loanDuration * 12;

    double monthlyPayment = loanAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, numberOfPayments) 
        / (pow(1 + monthlyInterestRate, numberOfPayments) - 1);
    double totalPayment = monthlyPayment * numberOfPayments;

    printf("\nYour monthly payment will be: $%.2lf\n", monthlyPayment);
    printf("Your total payment will be: $%.2lf\n", totalPayment);

    printf("\nThanks for using the Mortgage Calculator by Grateful Bot! Happy house hunting!\n");

    return 0;
}