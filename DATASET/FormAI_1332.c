//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: authentic
#include <stdio.h>
#include <math.h>

int main() {
    double loanAmount, interestRate, monthlyPayment;

    printf("Mortgage Calculator\n\n");

    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter interest rate (annual percentage rate): ");
    scanf("%lf", &interestRate);

    double monthlyInterestRate = (interestRate / 100.0) / 12.0;
    double numberOfPayments = 30 * 12; // assuming 30-year loan term
    double term = pow((1 + monthlyInterestRate), numberOfPayments);
    monthlyPayment = (loanAmount * term * monthlyInterestRate) / (term - 1);

    printf("\nYour monthly payment is: $%.2lf\n", monthlyPayment);

    return 0;
}