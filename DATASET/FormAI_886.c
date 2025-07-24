//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: satisfied
#include <stdio.h>
#include <math.h>

int main() {
    double principal, interestRate, monthlyRate, years;
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);
    printf("Enter the number of years: ");
    scanf("%lf", &years);

    monthlyRate = interestRate / 1200.0; // 12 months in a year, 100% as decimal
    int numOfPayments = round(years*12);
    double monthlyPayment = (principal*monthlyRate) / (1 - pow(1+monthlyRate, -numOfPayments));

    printf("\n\n");
    printf("Loan Amount: $%.2lf\n", principal);
    printf("Interest Rate: %.2lf %%\n", interestRate);
    printf("Loan Duration: %.0lf years\n", years);
    printf("==============================\n");
    printf("Monthly Payment: $%.2lf\n", monthlyPayment);
    printf("Total Payment: $%.2lf\n", monthlyPayment*numOfPayments);
    printf("Total Interest: $%.2lf\n", (monthlyPayment*numOfPayments)-principal);

    return 0;
}