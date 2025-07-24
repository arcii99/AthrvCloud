//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: careful
#include <stdio.h>
#include <math.h>

int main()
{
    double loan, interest_rate, term_years, monthly_payment, total_paid, total_interest;
    int term_months;
    
    // user input
    printf("Enter the loan amount: ");
    scanf("%lf", &loan);
    
    printf("Enter the annual interest rate: ");
    scanf("%lf", &interest_rate);
    
    printf("Enter the term of the loan in years: ");
    scanf("%lf", &term_years);
    term_months = term_years * 12;
    
    // calculation of monthly payment, total amount paid, and total interest paid
    double monthly_interest_rate = (interest_rate / 12) / 100.0;
    double base = 1 + monthly_interest_rate;
    double power = pow(base, -term_months);
    monthly_payment = (loan * monthly_interest_rate) / (1 - power);
    total_paid = monthly_payment * term_months;
    total_interest = total_paid - loan;
    
    // output
    printf("\nMonthly payment: $%.2lf\n", monthly_payment);
    printf("Total paid: $%.2lf\n", total_paid);
    printf("Total interest paid: $%.2lf\n", total_interest);
    
    return 0;
}