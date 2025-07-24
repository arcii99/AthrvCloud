//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: safe
#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate, years, monthly_rate, monthly_payment, total_interest, total_payment;

    printf("Enter principal amount: $");
    scanf("%lf", &principal);

    printf("Enter interest rate per year: ");
    scanf("%lf", &rate);

    printf("Enter number of years for mortgage: ");
    scanf("%lf", &years);

    monthly_rate = rate / 1200.0;
    monthly_payment = principal * monthly_rate / (1.0 - pow(1.0 + monthly_rate, -12.0 * years));
    total_payment = monthly_payment * 12.0 * years;
    total_interest = total_payment - principal;

    printf("\nMortgage payment is: $%.2f/month\n", monthly_payment);
    printf("\nTotal payment including interest is: $%.2f\n", total_payment);
    printf("Total interest paid is: $%.2f\n", total_interest);

    return 0;
}