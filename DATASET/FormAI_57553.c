//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double loan_amount, interest_rate, monthly_payment;
    int loan_tenure, num_payments;
    
    printf("Enter loan amount: ");
    scanf("%lf", &loan_amount);
    
    printf("Enter interest rate: ");
    scanf("%lf", &interest_rate);
    
    printf("Enter loan tenure (in years): ");
    scanf("%d", &loan_tenure);
    
    num_payments = loan_tenure * 12;
    monthly_payment = (loan_amount * interest_rate * pow(1 + interest_rate, num_payments)) /
                      (pow(1 + interest_rate, num_payments) - 1);
    
    printf("\nTotal Loan Amount : %.2lf", loan_amount);
    printf("\nInterest Rate : %.2lf", interest_rate);
    printf("\nLoan Tenure (in years) : %d", loan_tenure);
    printf("\nMonthly Payment : %.2lf", monthly_payment);
    printf("\nTotal Payment : %.2lf", monthly_payment * num_payments);
    printf("\nTotal Interest : %.2lf", (monthly_payment * num_payments) - loan_amount);
    
    return 0;
}