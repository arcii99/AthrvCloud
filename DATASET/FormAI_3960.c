//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include <stdio.h>
#include <math.h>

int main()
{
    int loan_amount;
    float interest_rate, monthly_payment, principal, monthly_interest, balance;
    int term_years, term_months, total_months;

    // Get user input
    printf("Enter loan amount: ");
    scanf("%d", &loan_amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter term in years: ");
    scanf("%d", &term_years);
    printf("Enter term in months: ");
    scanf("%d", &term_months);
    
    // Calculate total number of months
    total_months = term_years * 12 + term_months;

    // Calculate monthly interest rate
    monthly_interest = interest_rate / 1200;

    //Calculate monthly payment
    monthly_payment = (loan_amount * monthly_interest) / (1 - pow(1+monthly_interest, -total_months));

    // Print results
    printf("\nLoan Amount: $%d\n", loan_amount);
    printf("Interest Rate: %.2f%%\n", interest_rate);
    printf("Term: %d years %d months\n", term_years, term_months);
    printf("Monthly Payment: $%.2f\n", monthly_payment);

    // Print Amortization Table
    printf("\nAmortization Table:\n");
    printf("=====================\n");
    printf("Month\t Principal\tInterest\t Balance\n");
    printf("--------------------------------------------------\n");

    balance = loan_amount;

    for(int i = 1; i <= total_months; i++){
        if(balance <= 0) break;
        printf("%d\t$%.2f\t$%.2f\t$%.2f\n", i, principal, monthly_interest*balance, balance);
        principal = monthly_payment - monthly_interest*balance;
        balance = balance - principal;
    }

    return 0;
}