//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to calculate monthly payment
float calculate_monthly_payment(float loan_amount, float annual_interest_rate, float no_of_years) {
    float monthly_interest_rate = (annual_interest_rate / 100) / 12;
    int no_of_payments = no_of_years * 12;
    float monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -no_of_payments));
    return monthly_payment;
}

int main() {
    float loan_amount, annual_interest_rate, no_of_years;
    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter the loan amount in dollars: ");
    scanf("%f", &loan_amount);
    printf("Please enter the annual interest rate in percent: ");
    scanf("%f", &annual_interest_rate);
    printf("Please enter the number of years for repayment: ");
    scanf("%f", &no_of_years);

    float monthly_payment = calculate_monthly_payment(loan_amount, annual_interest_rate, no_of_years);
    printf("\nBased on your inputs, your monthly payment will be: $%.2f\n", monthly_payment);

    return 0;
}