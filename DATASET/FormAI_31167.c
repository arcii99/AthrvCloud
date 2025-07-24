//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: beginner-friendly
#include <stdio.h>

int main() {
    float loanAmount, interestRate, monthlyPayment;
    int loanTerm, numPayments;

    // Get user input
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);
    printf("Enter interest rate (in decimal form): ");
    scanf("%f", &interestRate);
    printf("Enter loan term (in years): ");
    scanf("%d", &loanTerm);

    // Calculate number of monthly payments
    numPayments = loanTerm * 12;

    // Calculate monthly mortgage payment
    float monthlyInterest = interestRate / 12;
    float temp = pow(1 + monthlyInterest, numPayments);
    monthlyPayment = loanAmount * (monthlyInterest * temp) / (temp - 1);

    // Output calculated monthly mortgage payment
    printf("Your monthly mortgage payment is: $%.2f\n", monthlyPayment);

    return 0;
}