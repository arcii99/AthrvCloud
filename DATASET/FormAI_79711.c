//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: dynamic
#include <stdio.h>
#include <math.h>

int main()
{
    // Define variables
    float principle, interest_rate, monthly_rate, term_years, term_months, total_amount;
    int payments_per_month;
    
    // Input values from user
    printf("Enter the loan amount (principle): $");
    scanf("%f", &principle);
    printf("Enter the annual interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter the loan term in years: ");
    scanf("%f", &term_years);
    printf("Enter the number of payments per month: ");
    scanf("%d", &payments_per_month);
    
    // Convert values to necessary units
    monthly_rate = (interest_rate / 100.0) / payments_per_month;
    term_months = term_years * 12.0;
    
    // Calculate the total amount to be paid
    total_amount = (principle * monthly_rate * pow(1 + monthly_rate, term_months)) / (pow(1 + monthly_rate, term_months) - 1);
    
    // Output the monthly payment amount
    printf("Your monthly payment amount is: $%.2f", total_amount);
    
    return 0;
}