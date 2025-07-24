//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: active
#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate, term;
    
    printf("Enter the principal amount in USD: ");
    scanf("%lf", &principal);
    
    printf("Enter the annual interest rate in percentage: ");
    scanf("%lf", &rate);
    
    printf("Enter the loan term in number of years: ");
    scanf("%lf", &term);

    double monthly_rate = rate / 1200;
    double monthly_payment = principal * monthly_rate / (1 - pow(1 + monthly_rate, -12 * term));
    double total_interest = monthly_payment * 12 * term - principal;

    printf("\n");
    printf("-----------------------------\n");
    printf("MORTGAGE CALCULATOR RESULT\n");
    printf("-----------------------------\n");
    printf("Loan Amount: $%.2lf\n", principal);
    printf("Interest Rate: %.2lf%%\n", rate);
    printf("Loan Term: %.0lf years\n", term);
    printf("Monthly Payment: $%.2lf\n", monthly_payment);
    printf("Total Interest: $%.2lf\n", total_interest);
    printf("-----------------------------\n");

    return 0;
}