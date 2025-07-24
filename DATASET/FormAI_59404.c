//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: protected
#include <stdio.h>

int main() {
    float loan_amount, interest_rate, monthly_payment;
    int terms;
    
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);
    
    printf("Enter the number of years of term: ");
    scanf("%d", &terms);
    
    // Calculate monthly payment
    float monthly_interest_rate = (interest_rate / 100) / 12;
    int num_payments = terms * 12;
    float numerator = loan_amount * monthly_interest_rate * powf(1 + monthly_interest_rate, num_payments);
    float denominator = powf(1 + monthly_interest_rate, num_payments) - 1;
    monthly_payment = numerator / denominator;
    
    printf("Monthly Payment: %.2f\n", monthly_payment);
    printf("Total Payment: %.2f\n", monthly_payment * num_payments);
    printf("Total Interest: %.2f\n", (monthly_payment * num_payments) - loan_amount);
   
    return 0;
}