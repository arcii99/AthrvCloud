//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: intelligent
#include <stdio.h>

int main() {
    double loan_amount, interest_rate, monthly_payment, balance;
    int loan_term, months;
    
    // Get loan amount
    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);
    
    // Get interest rate
    printf("Enter the interest rate per year: ");
    scanf("%lf", &interest_rate);
    
    // Get loan term in years
    printf("Enter the loan term in years: ");
    scanf("%d", &loan_term);
    
    // Convert yearly interest rate to monthly rate
    double monthly_rate = (interest_rate / 100) / 12;
    
    // Calculate number of months in loan term
    months = loan_term * 12;
    
    // Calculate monthly payment
    monthly_payment = (loan_amount * monthly_rate) / (1 - pow(1 + monthly_rate, -months));
    
    // Initialize balance
    balance = loan_amount;
    
    // Print monthly payment and total interest paid
    double total_interest = 0;
    printf("\nMonthly payment: $%.2lf\n\nAmortization Table:\n", monthly_payment);
    printf("Month\tInterest\tPrincipal\tBalance\n");
    for (int i = 1; i <= months; i++) {
        double interest = balance * monthly_rate;
        double principal = monthly_payment - interest;
        balance -= principal;
        total_interest += interest;
        printf("%d\t%.2lf\t\t%.2lf\t\t%.2lf\n", i, interest, principal, balance);
    }
    printf("\nTotal interest paid: $%.2lf\n", total_interest);
    
    return 0;
}