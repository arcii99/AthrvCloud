//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: visionary
#include <stdio.h>

int main() {
    double principal, interest_rate, monthly_payment, total_interest, total_payments;

    printf("MORTGAGE CALCULATOR\n\n");

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the interest rate (per year): ");
    scanf("%lf", &interest_rate);

    printf("Enter the monthly payment amount: ");
    scanf("%lf", &monthly_payment);

    printf("\nRESULTS\n\n");

    printf("Monthly Payment: $%.2lf\n", monthly_payment);

    int months = 0;
    total_interest = 0;
    total_payments = 0;

    while (principal > 0) {
        double interest = principal * (interest_rate / 100) / 12;

        if ((principal + interest) < monthly_payment) {
            monthly_payment = principal + interest;
        }

        double principal_payment = monthly_payment - interest;
        principal -= principal_payment;

        total_interest += interest;
        total_payments += monthly_payment;

        months++;
    }

    printf("Total Months: %d\n", months);
    printf("Total Interest: $%.2lf\n", total_interest);
    printf("Total Payments: $%.2lf\n", total_payments);

    return 0;
}