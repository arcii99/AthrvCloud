//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    float interest_rate, principal, duration, monthly_payment, total_interest, total_payment, balance, monthly_interest;
    int num_payments;

    printf("Enter principal amount: ");
    scanf("%f", &principal);

    printf("Enter annual interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter loan duration in years: ");
    scanf("%f", &duration);

    monthly_interest = interest_rate / 1200.0; // Monthly interest rate

    num_payments = duration * 12; // Number of monthly payments

    // Calculate monthly payment
    monthly_payment = (principal * monthly_interest) / (1.0 - pow(1.0 + monthly_interest, -num_payments));
    total_payment = num_payments * monthly_payment; // Total payment
    total_interest = total_payment - principal; // Total interest

    printf("\nMonthly payment: $%.2f\n", monthly_payment);
    printf("Total payment: $%.2f\n", total_payment);
    printf("Total interest: $%.2f\n", total_interest);

    // Print amortization table
    printf("\nAmortization table:\n\n");
    printf("Month\tPayment\tInterest\tBalance\n");
    printf("-----\t-------\t--------\t-------\n");

    balance = principal;

    for (int i = 1; i <= num_payments; i++) 
    {
        float interest = balance * monthly_interest; // Calculate interest
        float principal_paid = monthly_payment - interest; // Calculate principal paid
        balance -= principal_paid; // Update balance

        printf("%d\t$%.2f\t$%.2f\t$%.2f\n", i, monthly_payment, interest, balance);

        // Handle last payment
        if (i == num_payments && balance != 0) 
        {
            printf("\nLast Payment:\n");
            printf("Month\tPayment\tInterest\tBalance\n");
            printf("%d\t$%.2f\t$%.2f\t$0.00\n", i, balance + interest, interest);
        }
    }

    return 0;
}