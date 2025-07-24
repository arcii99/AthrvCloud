//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: systematic
#include <stdio.h>
#include <math.h>

int main() {
    
    double principal, interestRate, monthlyInterestRate, payment;
    int termInYears, numPayments;
    
    printf("Enter the loan principal: ");
    scanf("%lf", &principal);
    
    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);
    
    printf("Enter the term of the loan in years: ");
    scanf("%d", &termInYears);
    
    monthlyInterestRate = (interestRate / 100.0) / 12.0;
    numPayments = termInYears * 12;
    
    payment = (principal * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numPayments));
    
    printf("\n\n");
    printf("Loan amount: $%.2lf\n", principal);
    printf("Interest rate: %.2lf%%\n", interestRate);
    printf("Term: %d years\n", termInYears);
    printf("Monthly payment: $%.2lf\n", payment);
    
    return 0;
}