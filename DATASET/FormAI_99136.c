//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: introspective
/* 
   This program calculates the monthly mortgage payment 
   for a given loan amount, interest rate, and loan term. 
*/

#include <stdio.h>
#include <math.h>

int main() {
    // Initialize variables
    double principal, annual_interest_rate, monthly_interest_rate, monthly_payment;
    int loan_term_in_years, loan_term_in_months;

    // Ask for user input
    printf("Enter the loan amount: ");
    scanf("%lf", &principal);
    printf("Enter the annual interest rate as a decimal: ");
    scanf("%lf", &annual_interest_rate);
    printf("Enter the loan term in years: ");
    scanf("%d", &loan_term_in_years);

    // Convert loan term to months
    loan_term_in_months = loan_term_in_years * 12;

    // Calculate monthly interest rate
    monthly_interest_rate = annual_interest_rate / 12;

    // Calculate monthly mortgage payment
    monthly_payment = (principal * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -loan_term_in_months));

    // Display results to the user
    printf("For a loan amount of $%.2f at an annual interest rate of %.2f%% with a loan term of %d years,\n", principal, annual_interest_rate * 100, loan_term_in_years);
    printf("the monthly mortgage payment is $%.2f.\n", monthly_payment);

    return 0;
}