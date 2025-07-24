//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double loan_amount, interest_rate, monthly_payment, total_interest, total_payment;
    int years;

    printf("Welcome to the Mortgage Payment Calculator\n\n");

    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);

    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter the loan term in years: ");
    scanf("%d", &years);

    //Calculate the monthly interest rate and the number of payments
    double monthly_rate = interest_rate / 1200;
    int payments = years * 12;

    //Calculate the monthly payment
    monthly_payment = loan_amount * (monthly_rate / (1 - pow(1 + monthly_rate, -payments)));

    //Calculate the total payment and total interest
    total_payment = monthly_payment * payments;
    total_interest = total_payment - loan_amount;

    //Display the output
    printf("\nMonthly Payment: $%.2f\n", monthly_payment);
    printf("Total Payment: $%.2f\n", total_payment);
    printf("Total Interest: $%.2f\n", total_interest);

    return 0;
}