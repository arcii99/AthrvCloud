//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: invasive
#include <stdio.h>
#include <math.h>

int main()
{
    float loan, interest_rate, years, monthly_payment, total_payment;
    printf("Enter your loan amount: ");
    scanf("%f", &loan);
    printf("Enter your interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter the loan duration in years: ");
    scanf("%f", &years);
    interest_rate = interest_rate / 1200.0;
    monthly_payment = (loan * interest_rate * pow((1 + interest_rate), years * 12)) / (pow((1 + interest_rate), years * 12) - 1);
    total_payment = monthly_payment * years * 12;

    printf("\nMonthly Payment: %.2f", monthly_payment);
    printf("\nTotal Payment: %.2f", total_payment);

    return 0;
}