//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: calm
// This program is a mortgage calculator that calculates the monthly mortgage payment
// based on the loan amount, interest rate, and loan term. 

#include <stdio.h>
#include <math.h>

int main() {
    double loan_amount, interest_rate, monthly_payment, total_interest_paid;
    int loan_term, num_payments;

    printf("Welcome to the Mortgage Calculator! \n\n");

    // get user inputs
    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);

    printf("Enter the interest rate (APR): ");
    scanf("%lf", &interest_rate);

    printf("Enter the loan term (in years): ");
    scanf("%d", &loan_term);

    // calculate monthly mortgage payment
    double monthly_interest_rate = interest_rate / 1200;
    num_payments = loan_term * 12;
    double factor = pow((1 + monthly_interest_rate), num_payments);
    monthly_payment = (loan_amount * monthly_interest_rate * factor) / (factor - 1);

    // calculate total interest paid
    total_interest_paid = (monthly_payment * num_payments) - loan_amount;

    // print results
    printf("\n\n");
    printf("RESULT: \n");
    printf("Monthly Payment: $%.2f \n", monthly_payment);
    printf("Total Interest Paid: $%.2f \n", total_interest_paid);
    printf("\n\n");

    return 0;
}