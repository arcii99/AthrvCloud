//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: decentralized
#include <stdio.h>

int main() {
    float loan_amount, interest_rate, monthly_payment;
    int term_years;

    printf("Enter the loan amount: $");
    scanf("%f", &loan_amount);

    printf("Enter the annual interest rate: %%");
    scanf("%f", &interest_rate);

    printf("Enter the loan term (in years): ");
    scanf("%d", &term_years);

    // Calculate monthly interest rate
    float monthly_rate = interest_rate / 1200.0;

    // Calculate total number of payments
    int total_payments = term_years * 12;

    // Calculate monthly payment using formula
    // M = P [ i(1 + i)^n ] / [ (1 + i)^n – 1]
    monthly_payment = loan_amount * monthly_rate * pow(1 + monthly_rate, total_payments) / (pow(1 + monthly_rate, total_payments) - 1);

    printf("\nLoan Amount: $%.2f\n", loan_amount);
    printf("Annual Interest Rate: %.2f%%\n", interest_rate);
    printf("Loan Term: %d years\n", term_years);
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Total Payment: $%.2f\n", monthly_payment * total_payments);
    printf("Total Interest: $%.2f\n", (monthly_payment * total_payments) - loan_amount);

    return 0;
}