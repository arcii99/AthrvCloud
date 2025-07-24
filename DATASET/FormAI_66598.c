//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate, term, monthly_payment, remaining_balance;
    int payment_num = 1;
    
    // Get user inputs.
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the interest rate: ");
    scanf("%lf", &rate);
    printf("Enter the term in years: ");
    scanf("%lf", &term);
    
    // Convert interest rate from a percentage to a decimal.
    rate /= 100;
    
    // Calculate monthly interest rate and number of payments.
    double monthly_rate = rate / 12;
    int num_payments = term * 12;
    
    // Calculate the monthly payment using the formula:
    // M = P * (r(1+r)^n) / ((1+r)^n - 1)
    monthly_payment = principal * (monthly_rate * pow(1 + monthly_rate, num_payments)) / (pow(1 + monthly_rate, num_payments) - 1);
    
    // Print out the results.
    printf("\n");
    printf("Monthly Payment: %.2lf\n", monthly_payment);
    printf("\n");
    
    // Loop through each payment and print out the remaining balance.
    remaining_balance = principal;
    while (payment_num <= num_payments) {
        double interest_paid = monthly_rate * remaining_balance;
        double principal_paid = monthly_payment - interest_paid;
        remaining_balance -= principal_paid;
        printf("Payment #%d - Principal Paid: %.2lf, Interest Paid: %.2lf, Remaining Balance: %.2lf\n", payment_num, principal_paid, interest_paid, remaining_balance);
        payment_num++;
    }
    
    return 0;
}