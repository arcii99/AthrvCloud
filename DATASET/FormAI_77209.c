//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: optimized
#include <stdio.h>
#include <math.h>

int main()
{
    double principal, interest_rate, monthly_payment, total_interest, total_payment;
    int years, num_payments;
    
    // get input from user
    printf("Enter principal amount: ");
    scanf("%lf", &principal);
    printf("Enter interest rate per year (as a decimal): ");
    scanf("%lf", &interest_rate);
    printf("Enter number of years: ");
    scanf("%d", &years);
    
    // calculate number of payments
    num_payments = years * 12;   
    
    // calculate monthly payment
    double monthly_interest = interest_rate / 12;
    monthly_payment = principal * (monthly_interest * pow(1 + monthly_interest, num_payments)) /
                      (pow(1 + monthly_interest, num_payments) - 1);
    
    // calculate total payment and total interest
    total_payment = monthly_payment * num_payments;
    total_interest = total_payment - principal;
    
    // print out results
    printf("Principal amount: $%.2lf\n", principal);
    printf("Interest rate per year: %.2lf%%\n", interest_rate * 100);
    printf("Number of years: %d\n", years);
    printf("Monthly payment: $%.2lf\n", monthly_payment);
    printf("Total payment: $%.2lf\n", total_payment);
    printf("Total interest: $%.2lf\n", total_interest);
    
    return 0;
}