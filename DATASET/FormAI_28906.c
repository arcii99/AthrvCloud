//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: peaceful
#include <stdio.h>

int main()
{
    float principal;
    float interest_rate;
    float num_years;

    printf("Enter principal amount: ");
    scanf("%f", &principal);
    printf("Enter interest rate (in percent): ");
    scanf("%f", &interest_rate);
    printf("Enter the number of years: ");
    scanf("%f", &num_years);

    float interest_rate_decimal = interest_rate / 100;
    float monthly_interest_rate = interest_rate_decimal / 12;
    float num_payments = num_years * 12;

    float monthly_payment = (principal * monthly_interest_rate) /
                            (1 - (pow(1 + monthly_interest_rate, -num_payments)));

    printf("\n");
    printf("Mortgage Calculator\n");
    printf("-------------------\n");
    printf("Principal amount: $%.2f\n", principal);
    printf("Interest rate: %.2f%%\n", interest_rate);
    printf("Number of years: %.0f\n", num_years);
    printf("-------------------\n");
    printf("Monthly payment: $%.2f\n", monthly_payment);

    return 0;
}