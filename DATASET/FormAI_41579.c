//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: detailed
#include <stdio.h>
#include <stdbool.h>   // required for boolean data types

int main() {

    float loan_amount, interest_rate, monthly_payment, balance;   // declare required variables
    int loan_duration, months;
    bool valid_loan = false;   // boolean variable to check if the loan amount is valid

    // get loan amount
    do {
        printf("Enter the loan amount: ");
        scanf("%f", &loan_amount);

        // check if loan amount is valid
        if (loan_amount < 0) {
            printf("Invalid loan amount. Please enter a non-negative value.\n");
        } else {
            valid_loan = true;
        }
    } while (!valid_loan);

    // get interest rate and convert to monthly rate
    printf("Enter the annual interest rate: ");
    scanf("%f", &interest_rate);
    float monthly_rate = (interest_rate / 12) / 100;

    // get loan duration and convert to months
    printf("Enter the loan duration in years: ");
    scanf("%d", &loan_duration);
    months = loan_duration * 12;

    // calculate monthly payment
    monthly_payment = (monthly_rate * loan_amount) / (1 - pow(1 + monthly_rate, -months));

    // print monthly payment
    printf("Your monthly payment is: $%.2f\n", monthly_payment);

    // calculate and print amortization table
    printf("\nAmortization Table:\n");
    printf("-------------------\n");
    printf("Month\tPayment\tInterest\tBalance\n");
    printf("------------------------------------------------\n");

    balance = loan_amount;
    float total_interest = 0;  // variable to keep track of total interest paid

    // calculate and print each month's payment, interest, and balance
    for (int i = 1; i <= months; i++) {
        // calculate monthly interest
        float monthly_interest = balance * monthly_rate;
        total_interest += monthly_interest;

        // calculate monthly principal
        float monthly_principal = monthly_payment - monthly_interest;

        // update balance
        balance -= monthly_principal;

        // print row for current month
        printf("%d\t$%.2f\t$%.2f\t$%.2f\n", i, monthly_payment, monthly_interest, balance);

        // check if balance is fully paid off
        if (balance <= 0) {
            printf("\nYou have paid off your loan in %d months!\n", i);
            printf("Total interest paid: $%.2f\n", total_interest);
            return 0;   // exit program
        }
    }

    return 0;
}