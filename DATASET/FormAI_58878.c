//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

int main() {
    float loan_amt, interest_rate;
    int term_years;

    // Get user input for loan amount
    printf("Enter loan amount: $");
    scanf("%f", &loan_amt);

    // Get user input for interest rate
    printf("\nEnter interest rate: ");
    scanf("%f", &interest_rate);

    // Get user input for term in years
    printf("\nEnter term (in years): ");
    scanf("%d", &term_years);

    // Calculate monthly interest rate
    float monthly_interest_rate = interest_rate / 1200;

    // Calculate number of payments
    int num_payments = term_years * 12;

    // Calculate monthly payment amount
    float power = pow(1+monthly_interest_rate, num_payments);
    float monthly_payment = (loan_amt * monthly_interest_rate * power) / (power - 1);

    // Print out the results
    printf("\nLoan Amount: %.2f", loan_amt);
    printf("\nInterest Rate: %.2f%%", interest_rate);
    printf("\nTerm: %d years", term_years);
    printf("\n\nMonthly payment: $%.2f\n", monthly_payment);

    return 0;
}