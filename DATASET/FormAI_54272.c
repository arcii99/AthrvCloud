//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: innovative
#include <stdio.h>

int main() {
    printf("Welcome to the Mortgage Calculator!\n\n");

    // Prompt user for loan amount
    float loanAmount;
    printf("Enter the loan amount in dollars: ");
    scanf("%f", &loanAmount);

    // Prompt user for interest rate
    float interestRate;
    printf("Enter the interest rate as a decimal: ");
    scanf("%f", &interestRate);

    // Prompt user for length of loan
    int years;
    printf("Enter the length of the loan in years: ");
    scanf("%d", &years);

    // Convert interest rate to monthly
    float monthlyInterest = interestRate / 12;

    // Convert years to months
    int months = years * 12;

    // Calculate monthly payment
    float payment = (loanAmount * monthlyInterest) / (1 - (pow(1 + monthlyInterest, -months)));

    // Print out mortgage details
    printf("\nMortgage Details:\n");
    printf("Loan amount: $%.2f\n", loanAmount);
    printf("Interest rate (annual): %.2f%%\n", interestRate * 100);
    printf("Length of loan: %d years\n", years);
    printf("Monthly payment: $%.2f\n", payment);
    printf("Total payment: $%.2f\n", payment * months);

    return 0;
}