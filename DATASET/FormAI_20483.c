//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ephemeral
#include <stdio.h>

int main() {
    float loan_amount, interest_rate, monthly_payment, total_interest;
    int num_years, num_payments;

    printf("Welcome to the Mortgage Calculator!\n");

    // Get user inputs for loan information
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter the number of years to pay off the loan: ");
    scanf("%d", &num_years);

    // Calculate number of payments and monthly interest rate
    num_payments = num_years * 12;
    float monthly_interest_rate = interest_rate / (12 * 100);

    // Calculate monthly payment
    float discount_rate = pow((1 + monthly_interest_rate), -num_payments);
    monthly_payment = (loan_amount * monthly_interest_rate) / (1 - discount_rate);

    // Calculate total interest paid over the life of the loan
    total_interest = (monthly_payment * num_payments) - loan_amount;

    // Print out results
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Total Interest Paid: $%.2f\n", total_interest);

    return 0;
}