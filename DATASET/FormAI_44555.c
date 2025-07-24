//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: enthusiastic
#include <stdio.h>

int main() {
    float loan_amount, annual_interest_rate, monthly_interest_rate, num_of_years, num_of_payments;
    printf("Welcome to the Mortgage Calculator!\n\n");
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    printf("\n");

    printf("Enter the annual interest rate: ");
    scanf("%f", &annual_interest_rate);
    printf("\n");

    printf("Enter the number of years: ");
    scanf("%f", &num_of_years);
    printf("\n");

    monthly_interest_rate = annual_interest_rate / 1200; // Calculate monthly interest rate
    num_of_payments = num_of_years * 12; // Calculate number of monthly payments

    float monthly_payment = (loan_amount * monthly_interest_rate * pow(1 + monthly_interest_rate, num_of_payments))
                             / (pow(1 + monthly_interest_rate, num_of_payments) - 1);
    float total_interest = monthly_payment * num_of_payments - loan_amount;

    printf("\nYour monthly payment is: $%.2f\n", monthly_payment);
    printf("Your total interest paid will be: $%.2f\n", total_interest);
    printf("\nThank you for using the Mortgage Calculator!\n");
    return 0;
}