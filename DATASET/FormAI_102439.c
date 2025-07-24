//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: relaxed
#include <stdio.h>
#include <math.h>

int main()
{
    float loan_amount, interest_rate, monthly_payment, total_interest;
    int num_years, num_months;
    
    printf("Welcome to the Mortgage Calculator!\n");
    
    // Get user input
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    
    printf("Enter the annual interest rate: ");
    scanf("%f", &interest_rate);
    
    printf("Enter the number of years for the loan: ");
    scanf("%d", &num_years);
    
    // Calculate the monthly payment and total interest
    num_months = num_years * 12;
    float monthly_interest = interest_rate / 1200;
    monthly_payment = loan_amount * monthly_interest / (1 - pow(1 + monthly_interest, -num_months));
    total_interest = monthly_payment * num_months - loan_amount;
    
    // Print out the results
    printf("\nLoan amount: $%.2f\n", loan_amount);
    printf("Interest rate: %.2f%%\n", interest_rate);
    printf("Number of years: %d\n", num_years);
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total interest paid: $%.2f\n", total_interest);
    
    return 0;
}