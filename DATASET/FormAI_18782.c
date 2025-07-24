//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: accurate
#include <stdio.h>
#include <math.h>

int main() {
    float loan_amount, annual_interest_rate, monthly_interest_rate, monthly_payment, total_interest;
    int num_of_years, num_of_payments;

    // Input loan details
    printf("Loan amount: ");
    scanf("%f", &loan_amount);
    printf("Annual interest rate: ");
    scanf("%f", &annual_interest_rate);
    printf("Number of years: ");
    scanf("%d", &num_of_years);

    // Calculate monthly interest rate, number of payments
    monthly_interest_rate = annual_interest_rate / 12.0;
    num_of_payments = num_of_years * 12;

    // Calculate monthly payment amount
    monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -num_of_payments));
    printf("Monthly payment: $%.2f\n", monthly_payment);

    // Calculate total interest
    total_interest = (monthly_payment * num_of_payments) - loan_amount;
    printf("Total interest: $%.2f\n", total_interest);

    return 0;
}