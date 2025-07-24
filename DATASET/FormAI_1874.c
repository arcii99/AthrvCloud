//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: imaginative
#include<stdio.h>

int main() {
    float loanAmount, interestRate, monthlyPayment, totalPayment;
    int numberOfYears;

    // Taking user input
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);

    printf("Enter interest rate (per annum): ");
    scanf("%f", &interestRate);

    printf("Enter loan duration (in years): ");
    scanf("%d", &numberOfYears);

    // Converting interest rate into monthly
    interestRate = interestRate / (12 * 100);

    // Calculating monthly payment
    monthlyPayment = (loanAmount * interestRate) / (1 - pow(1 + interestRate, -numberOfYears*12));

    // Calculating total payment
    totalPayment = numberOfYears * 12 * monthlyPayment;

    // Displaying output
    printf("\nLoan Amount: %.2f", loanAmount);
    printf("\nInterest Rate: %.2f%%", interestRate * 12 * 100);
    printf("\nLoan Duration: %d years", numberOfYears);
    printf("\nMonthly Payment: %.2f", monthlyPayment);
    printf("\nTotal Payment: %.2f\n", totalPayment);

    return 0;
}