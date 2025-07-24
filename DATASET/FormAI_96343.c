//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complete
#include <stdio.h>
#include <math.h>

int main() {
    float principal, rate, monthlyRate, years, payments;
    float mortgagePayment, totalPayments, totalInterest;

    printf("Enter loan principal: ");
    scanf("%f", &principal);

    printf("Enter annual interest rate (as decimal): ");
    scanf("%f", &rate);

    printf("Enter loan term (in years): ");
    scanf("%f", &years);

    payments = years * 12;
    monthlyRate = rate / 12.0;

    mortgagePayment = (principal * monthlyRate * pow(1 + monthlyRate, payments)) / (pow(1 + monthlyRate, payments) - 1);
    totalPayments = mortgagePayment * payments;
    totalInterest = totalPayments - principal;

    printf("\n");
    printf("Mortgage Payment Calculator\n");
    printf("---------------------------\n");
    printf("Loan Amount: $%.2f\n", principal);
    printf("Interest Rate: %.3f%%\n", rate * 100);
    printf("Loan Term: %.0f years\n", years);
    printf("Monthly Payment: $%.2f\n", mortgagePayment);
    printf("Total Payments: $%.2f\n", totalPayments);
    printf("Total Interest: $%.2f\n", totalInterest);

    return 0;
}