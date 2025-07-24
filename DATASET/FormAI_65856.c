//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: lively
#include <stdio.h>
#include <math.h>

int main() {
    float principal, interestRate, monthlyRate, totalPaid, monthlyPayment;
    int numPayments;

    // get user input
    printf("Enter the principal amount of the mortgage: $");
    scanf("%f", &principal);
    printf("Enter the interest rate of the mortgage: ");
    scanf("%f", &interestRate);
    printf("Enter the number of payments on the mortgage: ");
    scanf("%d", &numPayments);

    // calculate monthly interest rate
    monthlyRate = interestRate / 1200;

    // calculate monthly payment
    monthlyPayment = (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -numPayments));

    // calculate total amount paid
    totalPaid = monthlyPayment * numPayments;

    // output results
    printf("\nFor a mortgage of $%.2f at %.2f%% interest rate for %d months:\n", principal, interestRate, numPayments);
    printf("Monthly payment will be: $%.2f\n", monthlyPayment);
    printf("Total amount paid will be: $%.2f\n", totalPaid);

    return 0;
}