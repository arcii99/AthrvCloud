//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: protected
#include <stdio.h>
#include <math.h>

int main() {
    // declare variables
    float principal, rate, term, monthly_payment, interest, total_interest, total_payment;
    int num_payments;
    
    // get user input
    printf("Enter the amount of the loan: ");
    scanf("%f", &principal);
    printf("Enter the interest rate per year: ");
    scanf("%f", &rate);
    printf("Enter the term of the loan in years: ");
    scanf("%f", &term);
    
    // convert annual interest rate to monthly rate
    rate /= 12*100;
    
    // compute number of payments
    num_payments = term*12;
    
    // compute monthly payment
    monthly_payment = (principal * rate * pow(1 + rate, num_payments)) / (pow(1 + rate, num_payments) - 1);
    
    // compute total payment and total interest
    total_payment = monthly_payment * num_payments;
    total_interest = total_payment - principal;
    
    // print results
    printf("\nResults:\n");
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total payment: $%.2f\n", total_payment);
    printf("Total interest: $%.2f\n", total_interest);
    
    return 0;
}