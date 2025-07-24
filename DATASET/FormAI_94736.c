//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: sophisticated
#include <stdio.h>
#include <math.h>

#define MONTHS_IN_YEAR 12

int main()
{
    float principal, rate, years;
    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the interest rate in percentage: ");
    scanf("%f", &rate);

    printf("Enter the number of years: ");
    scanf("%f", &years);

    float monthly_rate = rate / (100 * MONTHS_IN_YEAR);
    float total_months = years * MONTHS_IN_YEAR;

    float numerator = pow(1 + monthly_rate, total_months) * monthly_rate;

    float denominator = pow(1 + monthly_rate, total_months) - 1;
    float monthly_payment = principal * (numerator / denominator);

    printf("\n==================================================\n");
    printf("Mortgage Calculation Summary\n");
    printf("==================================================\n");
    printf("Principal amount: %.2f\n", principal);
    printf("Interest rate: %.2f percent\n", rate);
    printf("Number of years: %.2f\n", years);
    printf("Monthly payment: %.2f\n", monthly_payment);
    printf("Total payment: %.2f\n", monthly_payment * total_months);

    return 0;
}