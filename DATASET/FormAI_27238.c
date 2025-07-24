//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: imaginative
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, time, emi, numerator, denominator;

    printf("Welcome to the Mortgage Calculator\n\n");

    printf("Please enter the loan amount: ");
    scanf("%f", &principal);

    printf("Please enter the interest rate per year (in decimal): ");
    scanf("%f", &rate);

    printf("Please enter the time period of the loan (in years): ");
    scanf("%f", &time);

    rate /= 12.0; // converting yearly rate to monthly rate
    time *= 12.0; // converting year into months

    numerator = (principal * rate * pow((1 + rate), time));
    denominator = (pow((1 + rate), time) - 1);

    emi = numerator / denominator;

    printf("\n*****************************************************************\n");
    printf("Your monthly EMI is = $%.2f\n", emi);
    printf("Total paid after %.0f years = $%.2f\n", time/12, emi*time);
    printf("Total interest payable = $%.2f\n", (emi*time)-principal);
    printf("*****************************************************************\n");

    return 0;
}