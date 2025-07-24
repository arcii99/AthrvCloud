//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: beginner-friendly
#include <stdio.h>

int main() {
    float loanAmount, interestRate, monthlyPayment;
    int years;

    printf("Let's calculate your mortgage details!\n\n");

    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);

    printf("Enter the interest rate (percentage): ");
    scanf("%f", &interestRate);

    printf("Enter the number of years: ");
    scanf("%d", &years);

    // convert the percentage interest rate to decimal
    interestRate /= 100;

    // calculate the monthly interest rate
    float monthlyInterestRate = interestRate / 12;

    // calculate the number of months
    int months = years * 12;

    // calculate the monthly payment using the formula
    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -months));

    printf("\nYour monthly payment is: $%.2f\n", monthlyPayment);

    printf("\nHere are the mortgage details:\n");
    printf("Loan Amount: $%.2f\n", loanAmount);
    printf("Interest Rate: %.2f%%\n", interestRate * 100);
    printf("Loan Period: %d years\n", years);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payment: $%.2f\n", monthlyPayment * months);

    return 0;
}