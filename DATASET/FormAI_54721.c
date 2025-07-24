//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: energetic
#include <stdio.h>

int main() {
    int loanAmount, termYears, termMonths, paymentsPerYear, numPayments;
    double interestRate, monthlyPayment, totalInterestPaid, totalPayment;

    printf("Enter the loan amount: ");
    scanf("%d", &loanAmount);

    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);

    printf("Enter the term in years: ");
    scanf("%d", &termYears);

    printf("Enter the term in months: ");
    scanf("%d", &termMonths);

    printf("Enter the number of payments per year: ");
    scanf("%d", &paymentsPerYear);

    numPayments = (termYears * paymentsPerYear) + (termMonths / (12 / paymentsPerYear));

    double monthlyInterestRate = interestRate / (paymentsPerYear * 100);

    double power = 1;
    for (int i = 0; i < numPayments; i++) {
        power *= (1 + monthlyInterestRate);
    }

    monthlyPayment = (loanAmount * monthlyInterestRate * power) / (power - 1);

    totalInterestPaid = (monthlyPayment * numPayments) - loanAmount;
    totalPayment = loanAmount + totalInterestPaid;

    printf("\nMonthly payment: $%.2lf", monthlyPayment);
    printf("\nTotal interest paid: $%.2lf", totalInterestPaid);
    printf("\nTotal payment: $%.2lf", totalPayment);

    return 0;
}