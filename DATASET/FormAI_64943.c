//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: systematic
#include <stdio.h>
#include <math.h>

int main() {
    double loanAmount, interestRate, monthlyPayment, totalPayment;
    int years;

    // Get user input
    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);
    printf("Enter interest rate: ");
    scanf("%lf", &interestRate);
    printf("Enter number of years: ");
    scanf("%d", &years);

    // Convert interest rate from percentage to decimal form
    interestRate /= 100.0;

    // Calculate monthly payment and total payment
    monthlyPayment = (loanAmount * interestRate * pow(1 + interestRate, years * 12)) / (pow(1 + interestRate, years * 12) - 1);
    totalPayment = monthlyPayment * years * 12;

    // Display results
    printf("Monthly payment: $%.2f\n", monthlyPayment);
    printf("Total payment: $%.2f\n", totalPayment);

    return 0;
}