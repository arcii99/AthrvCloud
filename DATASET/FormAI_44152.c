//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: automated
#include <stdio.h>
#include <math.h>

int main()
{
    double loan_amount, interest_rate, monthly_payment;
    int loan_term;

    printf("Enter loan amount: ");
    scanf("%lf", &loan_amount);

    printf("Enter annual interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter loan term (in years): ");
    scanf("%d", &loan_term);

    // convert annual interest rate to monthly interest rate
    double monthly_rate = interest_rate / 1200;

    // calculate the total number of payments
    int num_payments = loan_term * 12;

    // calculate the monthly payment
    monthly_payment = (loan_amount * monthly_rate) / 
                      (1 - pow(1 + monthly_rate, -num_payments));

    // display the monthly payment rounded to two decimal places
    printf("Monthly payment: $%.2lf\n", monthly_payment);

    // display the total amount paid over the life of the loan
    double total_paid = monthly_payment * num_payments;
    printf("Total amount paid: $%.2lf\n", total_paid);

    return 0;
}