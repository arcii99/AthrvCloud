//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: satisfied
#include <stdio.h>
#include <math.h>

int main() {
    double loan_amount, interest_rate, num_years, monthly_payment;
    int num_payments;

    //Getting input values from the user
    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);
    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter the number of years: ");
    scanf("%lf", &num_years);

    //Converting years to months
    num_payments = num_years * 12;

    //Calculating monthly interest rate from annual interest rate
    interest_rate = interest_rate / 1200;

    // Calculating the monthly payment
    monthly_payment = (loan_amount * interest_rate) / (1 - (pow(1 / (1 + interest_rate), num_payments)));
    
    printf("Monthly Payment: $%.2f\n", monthly_payment);

    return 0;
}