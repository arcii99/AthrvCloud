//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: light-weight
#include <stdio.h>
#include <math.h>

int main() {
    float principal, interest, monthlyInterest, numPayments, monthlyPayment, totalPaid, totalInterest;
    printf("Enter the loan principal: ");
    scanf("%f", &principal);

    printf("Enter the interest rate: ");
    scanf("%f", &interest);
    monthlyInterest = interest / 1200;

    printf("Enter the number of payments (in months): ");
    scanf("%f", &numPayments);

    monthlyPayment = (principal * monthlyInterest) / (1 - powf(1 + monthlyInterest, -numPayments));
    totalPaid = numPayments * monthlyPayment;
    totalInterest = totalPaid - principal;

    printf("\n");
    printf("Principal: %.2f\n", principal);
    printf("Interest rate: %.2f\n", interest);
    printf("Number of payments: %.2f\n", numPayments);
    printf("Monthly payment: %.2f\n", monthlyPayment);
    printf("Total paid: %.2f\n", totalPaid);
    printf("Total interest: %.2f\n", totalInterest);
    return 0;
}