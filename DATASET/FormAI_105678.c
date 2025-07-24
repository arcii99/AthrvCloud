//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: calm
#include <stdio.h>
#include <math.h>

int main() {
    double loanAmount, interestRate, monthlyPayment, totalPayment, totalInterest;
    int years, months;

    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter interest rate in percentage: ");
    scanf("%lf", &interestRate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    months = years * 12;
    interestRate = interestRate / 100 / 12;

    double fNumerator = loanAmount * interestRate;
    double fDenominator = 1.0 - (1.0 / pow(1.0 + interestRate, (double)months));
    monthlyPayment = fNumerator / fDenominator;

    totalPayment = monthlyPayment * months;
    totalInterest = totalPayment - loanAmount;

    printf("\n");
    printf("Loan amount: $%.2lf\n", loanAmount);
    printf("Interest rate: %.2lf%%\n", interestRate * 100 * 12);
    printf("Number of years: %d\n", years);
    printf("Monthly payment: $%.2lf\n", monthlyPayment);
    printf("Total payment: $%.2lf\n", totalPayment);
    printf("Total interest: $%.2lf\n", totalInterest);

    return 0;
}