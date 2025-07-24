//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Cryptic
#include <stdio.h>
#include <math.h>

int main() {
    float principal, interestRate, monthlyPayment, totalInterest, totalAmountPaid;
    int numPayments;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    
    printf("Enter the interest rate (in percentage): ");
    scanf("%f", &interestRate);
    interestRate /= 100.0;

    printf("Enter the number of payments: ");
    scanf("%d", &numPayments);

    monthlyPayment = (principal * interestRate * pow(1 + interestRate, numPayments)) / (pow(1 + interestRate, numPayments) - 1);

    printf("Monthly payment: $%.2f\n", monthlyPayment);

    totalInterest = monthlyPayment * numPayments - principal;
    totalAmountPaid = monthlyPayment * numPayments;

    printf("Total interest paid: $%.2f\n", totalInterest);
    printf("Total amount paid: $%.2f\n", totalAmountPaid);
    
    return 0;
}