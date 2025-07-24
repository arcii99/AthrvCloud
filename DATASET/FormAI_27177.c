//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: thoughtful
/* This is a mortgage calculator program written in C language. It is a user-friendly program that accepts input values from the user and calculates the monthly payment on a mortgage loan. */

#include <stdio.h>
#include <math.h>

int main() {
    double loan_amount, interest_rate, monthly_payment; // variables to hold user input
    double monthly_interest, num_payments, total_interest; // variables for calculation purposes
    
    // prompt user to enter loan amount
    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);
    
    // prompt user to enter interest rate
    printf("Enter the interest rate (as a decimal): ");
    scanf("%lf", &interest_rate);
    
    // prompt user to enter number of payments
    printf("Enter the number of payments: ");
    scanf("%lf", &num_payments);
    
    // calculate monthly interest rate
    monthly_interest = interest_rate / 12;
    
    // calculate monthly payment using formula
    monthly_payment = (loan_amount * monthly_interest) / (1 - pow(1 + monthly_interest, -num_payments));
    
    // calculate total interest paid over life of loan
    total_interest = (monthly_payment * num_payments) - loan_amount;
    
    // output monthly payment and total interest paid
    printf("Monthly Payment: $%.2lf\n", monthly_payment);
    printf("Total Interest Paid: $%.2lf\n", total_interest);
    
    return 0; // terminate program
}