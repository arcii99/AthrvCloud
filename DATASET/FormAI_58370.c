//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: future-proof
#include <stdio.h>
#include <math.h>

#define MONTHS_IN_YEAR 12

int main() {

    double principal, annualRate, monthlyRate, monthlyPayment, totalPayment, interest, balance;

    int numOfYears, numOfMonths, numOfPayments;

    printf("Enter the principal amount of the mortgage: ");
    scanf("%lf", &principal);

    printf("Enter the annual interest rate (in percentage): ");
    scanf("%lf", &annualRate);

    printf("Enter the number of years of the mortgage: ");
    scanf("%d", &numOfYears);

    numOfMonths = numOfYears * MONTHS_IN_YEAR;

    monthlyRate = annualRate / (MONTHS_IN_YEAR * 100.0);
    numOfPayments = numOfYears * MONTHS_IN_YEAR;

    monthlyPayment = (principal * monthlyRate * pow(1 + monthlyRate, numOfPayments)) / (pow(1 + monthlyRate, numOfPayments) - 1);
    totalPayment = monthlyPayment * numOfPayments;

    printf("\nMortgage Details:\n");
    printf("Principal: $%.2lf\n", principal);
    printf("Annual Interest Rate: %.2lf%%\n", annualRate);
    printf("Number of Years: %d\n", numOfYears);
    printf("Monthly Payment: $%.2lf\n", monthlyPayment);
    printf("Total Payment: $%.2lf\n", totalPayment);

    printf("\nPayment Schedule:\n");
    printf("Month\tPayment\t\tInterest\tBalance\n");

    for (int i = 1; i <= numOfPayments; i++) {
        interest = principal * monthlyRate;
        balance = principal - (monthlyPayment - interest);
        printf("%d\t%.2lf\t\t%.2lf\t\t%.2lf\n", i, monthlyPayment, interest, balance);
        principal = balance;
    }

    return 0;
}