//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>
#include <math.h>

int main()
{
    double loan_amount,interest_rate,monthly_interest_rate,monthly_payment;
    int mortgage_term;

    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);

    printf("Enter the interest rate (in percentage): ");
    scanf("%lf", &interest_rate);

    printf("Enter the mortgage term (in years): ");
    scanf("%d", &mortgage_term);

    monthly_interest_rate = interest_rate / 1200; //Calculating monthly interest rate
    int number_of_payments = mortgage_term * 12; // Calculating total number of monthly payments

    // Calculating the monthly payment using the formula
    monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -number_of_payments));

    printf("Your monthly payment is: $%.2lf", monthly_payment);

    return 0;
}