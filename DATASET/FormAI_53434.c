//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define MONTHS_IN_YEAR 12

int main() {
    double loan_amount, interest_rate, monthly_payment, total_payment, monthly_rate;
    int years, months;
    printf("Enter loan amount: ");
    scanf("%lf", &loan_amount);

    printf("Enter interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter loan duration in years: ");
    scanf("%d", &years);

    printf("Enter loan duration in months: ");
    scanf("%d", &months);

    monthly_rate = interest_rate / (MONTHS_IN_YEAR * 100.0);
    int total_months = years * MONTHS_IN_YEAR + months;

    if (interest_rate == 0) {
        monthly_payment = loan_amount / total_months;
    } else {
        double factor = pow(1 + monthly_rate, total_months);
        monthly_payment = loan_amount * (monthly_rate * factor) / (factor - 1);
    }

    total_payment = monthly_payment * total_months;

    printf("Monthly Payment: %.2lf\n", monthly_payment);
    printf("Total Payment: %.2lf\n", total_payment);
    printf("Total Interest: %.2lf\n", total_payment - loan_amount);

    return 0;
}