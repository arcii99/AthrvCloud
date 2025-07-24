//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: futuristic
#include <stdio.h>
#include <math.h>

int main()
{
    // Welcome Message
    printf("Welcome to the Futuristic Mortgage Calculator!\n");

    // Getting Input from User

    printf("Please enter the mortgage amount: ");
    float mortgageAmount;
    scanf("%f", &mortgageAmount);

    printf("Please enter the interest rate: ");
    float interestRate;
    scanf("%f", &interestRate);

    printf("Please enter the loan period (in years): ");
    int loanPeriod;
    scanf("%d", &loanPeriod);

    // Calculation

    float monthlyInterestRate = interestRate / 1200;
    int numberOfPayments = loanPeriod * 12;

    float monthlyPayment = mortgageAmount * monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -numberOfPayments));

    float totalPayment = monthlyPayment * numberOfPayments;
    float totalInterest = totalPayment - mortgageAmount;

    // Output

    printf("\n");
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payment: $%.2f\n", totalPayment);
    printf("Total Interest: $%.2f\n", totalInterest);

    // Goodbye Message
    printf("\nThank you for using Futuristic Mortgage Calculator!\n");

    return 0;
}