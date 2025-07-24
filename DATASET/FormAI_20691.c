//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: detailed
#include <stdio.h>
#include <math.h>

int main()
{
    float amount, interest_rate, monthly_payment, num_years;

    printf("Enter the loan amount: ");
    scanf("%f", &amount);
    printf("Enter the interest rate per year (in percentage): ");
    scanf("%f", &interest_rate);
    printf("Enter the number of years for loan repayment: ");
    scanf("%f", &num_years);

    // Convert annual interest rate to monthly interest rate
    float monthly_rate = interest_rate / 1200;

    // Calculate the number of monthly payments
    int num_payments = num_years * 12;

    // Calculate the monthly payment using the formula
    monthly_payment = amount * monthly_rate * pow(1 + monthly_rate, num_payments) /
                      (pow(1 + monthly_rate, num_payments) - 1);

    // Display the monthly payment
    printf("\nMonthly payment: $%.2f\n", monthly_payment);

    // Calculate and display the total amount paid over the loan term
    float total_amount_paid = monthly_payment * num_payments;
    printf("Total amount paid: $%.2f\n", total_amount_paid);

    // Calculate and display the total interest paid over the loan term
    float total_interest_paid = total_amount_paid - amount;
    printf("Total interest paid: $%.2f\n", total_interest_paid);

    return 0;
}