//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: protected
#include <stdio.h>
#include <math.h>

int main()
{
    // Loan variables
    double loan_amount;
    double interest_rate;
    int loan_term;
    
    // Payment variables
    double monthly_payment;
    double total_payment;
    double total_interest;
    
    // User inputs loan details
    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);
    
    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);
    interest_rate = interest_rate / 100.0 / 12.0; // Monthly interest rate
    
    printf("Enter the loan term (in years): ");
    scanf("%d", &loan_term);
    loan_term = loan_term * 12; // Total payments
    
    // Calculate monthly payment
    monthly_payment = (loan_amount * interest_rate * pow(1 + interest_rate, loan_term)) / (pow(1 + interest_rate, loan_term) - 1);
    
    // Calculate total payment and total interest
    total_payment = monthly_payment * loan_term;
    total_interest = total_payment - loan_amount;
    
    // Display results
    printf("\nLoan Details:\n");
    printf("Loan amount (principal) = $%.2f\n", loan_amount);
    printf("Interest rate = %.2f%% per year\n", interest_rate * 100.0 * 12.0);
    printf("Loan term = %d months\n", loan_term);
    printf("\nMonthly payment = $%.2f\n", monthly_payment);
    printf("Total payment = $%.2f (including $%.2f interest)\n", total_payment, total_interest);
    
    return 0;
}