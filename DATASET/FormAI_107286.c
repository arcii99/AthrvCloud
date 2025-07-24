//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: secure
#include<stdio.h>
#include<math.h>

float calculateMonthlyPayment(float principal, float interestRate, int years);
float calculateTotalPayment(float monthlyPayment, int years);

int main()
{
    float principal, interestRate, monthlyPayment, totalPayment;
    int years;

    printf("Enter the loan principal amount: ");
    scanf("%f", &principal);

    printf("Enter the interest rate per year (in percentage): ");
    scanf("%f", &interestRate);

    printf("Enter the number of years for the loan: ");
    scanf("%d", &years);

    monthlyPayment = calculateMonthlyPayment(principal, interestRate, years);
    totalPayment = calculateTotalPayment(monthlyPayment, years);

    printf("\nMonthly payment: $%.2f", monthlyPayment);
    printf("\nTotal payment: $%.2f", totalPayment);

    return 0;
}

float calculateMonthlyPayment(float principal, float interestRate, int years)
{
    float r = interestRate / 1200;
    int n = years * 12;

    float monthlyPayment = principal * r / (1 - powf(1 + r, -n));

    return monthlyPayment;
}

float calculateTotalPayment(float monthlyPayment, int years)
{
    float totalPayment = monthlyPayment * years * 12;

    return totalPayment;
}