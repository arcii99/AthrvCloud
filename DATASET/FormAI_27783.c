//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, years, emi, interest;
    int total_payments;

    printf("Welcome to the Mortgage Calculator!\n\n");

    printf("Enter your principal amount: ");
    scanf("%f", &principal);

    printf("Enter your rate of interest: ");
    scanf("%f", &rate);

    printf("Enter the number of years: ");
    scanf("%f", &years);

    printf("Enter the total number of payments: ");
    scanf("%d", &total_payments);

    rate = rate / (12 * 100);
    emi = (principal * rate * pow(1 + rate, years * 12)) / (pow(1 + rate, years * 12) - 1);
    interest = total_payments * emi - principal;

    printf("\nYour monthly EMI would be: $%.2f\n", emi);
    printf("Your total interest paid over %d payments would be: $%.2f", total_payments, interest);

    return 0;
}