//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: calm
#include <stdio.h>

int main() {
    double loanAmount, interestRate, numYears;
    double monthlyPayment, totalPayment;

    // Get input values from user
    printf("Enter the loan amount: $");
    scanf("%lf", &loanAmount);
    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);
    printf("Enter the number of years for the loan: ");
    scanf("%lf", &numYears);

    // Calculate monthly and total payment
    double r = interestRate / 1200.0; // monthly interest rate
    double n = numYears * 12.0; // number of months
    double denominator = 1.0 - pow(1.0+r, -n);
    monthlyPayment = (loanAmount * r) / denominator;
    totalPayment = monthlyPayment * n;

    // Display output to user
    printf("\nMonthly Payment: $%.2lf\n", monthlyPayment);
    printf("Total Payment: $%.2lf\n", totalPayment);

    return 0;
}