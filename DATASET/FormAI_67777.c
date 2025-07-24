//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: authentic
#include <stdio.h>

int main() {
    float principal, interestRate, monthlyInterestRate, payment, balance;
    int termInMonths, numOfPaymentsMade, monthsLeft;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the interest rate (in percentage): ");
    scanf("%f", &interestRate);

    printf("Enter the term of the loan (in months): ");
    scanf("%d", &termInMonths);

    monthlyInterestRate = (interestRate / 100) / 12;
    payment = (monthlyInterestRate * principal) / (1 - pow(1 + monthlyInterestRate, -termInMonths));
    balance = principal;

    printf("\nMonthly Payment: $%.2f\n", payment);
    printf("Payment Schedule:\n\n");
    printf("Month\tPayment\tBalance\n");

    numOfPaymentsMade = 0;
    while (numOfPaymentsMade < termInMonths) {
        numOfPaymentsMade++;
        balance = balance + (monthlyInterestRate * balance) - payment;
        printf("%d\t$%.2f\t$%.2f\n", numOfPaymentsMade, payment, balance);
    }

    monthsLeft = termInMonths - numOfPaymentsMade;
    if (monthsLeft > 0) {
        balance = balance + (monthlyInterestRate * balance);
        printf("\n%d Monthly Payments of $%.2f remain Your Loan Balance is $%.2f\n", monthsLeft, payment, balance);
    }

    return 0;
}