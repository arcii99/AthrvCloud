//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double principal, rate, num_years, monthly_rate, total_payments;
    printf("Enter principal amount: ");
    scanf("%lf", &principal);
    printf("Enter annual interest rate: ");
    scanf("%lf", &rate);
    printf("Enter number of years to pay off the mortgage: ");
    scanf("%lf", &num_years);

    monthly_rate = rate / (12 * 100);
    total_payments = num_years * 12;

    double interest_factor = pow((1 + monthly_rate), total_payments);
    double payment = (principal * monthly_rate * interest_factor) / (interest_factor - 1);

    printf("\nMortgage Payment: $%.2lf/month\n", payment);

    return 0;
}