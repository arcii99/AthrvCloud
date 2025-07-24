//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float loan_amount, interest_rate, monthly_payment, balance;
    int loan_term, num_payments;
    
    // Get user inputs
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);
    
    printf("Enter the loan term in years: ");
    scanf("%d", &loan_term);
    
    // Convert interest rate to monthly rate
    interest_rate /= 100.0;
    interest_rate /= 12.0;
    
    // Calculate number of payments
    num_payments = loan_term * 12;
    
    // Calculate monthly payment
    monthly_payment = (loan_amount * interest_rate * pow(1 + interest_rate, num_payments)) / (pow(1 + interest_rate, num_payments) - 1);
    
    // Print monthly payment
    printf("Your monthly payment is: $%.2f\n", monthly_payment);
    
    // Print amortization table
    balance = loan_amount;
    printf("\nAmortization Table\n");
    printf("=======================================\n");
    printf("Payment\tInterest\tPrincipal\tBalance\n");
    
    for (int i = 1; i <= num_payments; i++) {
        float interest = balance * interest_rate;
        float principal = monthly_payment - interest;
        balance -= principal;
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", i, interest, principal, balance);
    }
    
    return 0;
}