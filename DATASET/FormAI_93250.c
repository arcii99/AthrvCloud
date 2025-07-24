//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: dynamic
#include <stdio.h>
#include <math.h>

int main()
{
    float loan_amount, interest_rate, monthly_payment; // Variables to hold user input
    float monthly_interest_rate, total_interest, total_payment; // Additional variables

    printf("Welcome to Mortgage Calculator!\n\n");

    // Get user input
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    printf("Enter the interest rate (in decimals): ");
    scanf("%f", &interest_rate);
    printf("Enter the monthly payment amount: ");
    scanf("%f", &monthly_payment);

    // Calculate monthly interest rate
    monthly_interest_rate = interest_rate / 12;

    // Calculate number of months to pay off loan
    int num_of_months = ceil(log(monthly_payment / (monthly_payment - (monthly_interest_rate * loan_amount))) / log(1 + monthly_interest_rate));

    // Calculate total interest and total payment
    total_interest = (monthly_payment * num_of_months) - loan_amount;
    total_payment = loan_amount + total_interest;

    // Output results
    printf("\n\nLoan Amount: $%.2f\n", loan_amount);
    printf("Interest Rate: %.2f%%\n", interest_rate * 100);
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Number of Months to Pay off Loan: %d\n", num_of_months);
    printf("Total Interest Paid: $%.2f\n", total_interest);
    printf("Total Payment: $%.2f\n", total_payment);

    return 0;
}