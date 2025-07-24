//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: unmistakable
#include <stdio.h>
#include <math.h>

int main()
{
    float loan_amount, interest_rate, months, monthly_payment, total_interest, total_amount;

    printf("Welcome to the Mortgage Calculator!\n\n");

    // Input loan amount
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);

    // Input interest rate
    printf("Enter the interest rate (in percentage): ");
    scanf("%f", &interest_rate);

    // Input loan period in months
    printf("Enter the loan period (in months): ");
    scanf("%f", &months);

    // Calculate monthly interest rate
    float monthly_interest_rate = interest_rate / 100 / 12;

    // Calculate monthly payment
    monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -months));

    // Calculate total interest
    total_interest = monthly_payment * months - loan_amount;

    // Calculate total amount paid
    total_amount = monthly_payment * months;

    // Display results
    printf("\n");
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Total Interest: $%.2f\n", total_interest);
    printf("Total Amount Paid: $%.2f\n", total_amount);

    return 0;
}