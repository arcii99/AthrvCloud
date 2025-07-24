//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

int main() {
    float interest_rate, loan_amount, monthly_payment, monthly_interest_rate, balance, term_years, term_months;
    int i;

    // Input parameters
    printf("Enter loan amount: ");
    scanf("%f", &loan_amount);

    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter loan term in years: ");
    scanf("%f", &term_years);

    // Calculation variables
    monthly_interest_rate = interest_rate / 1200;
    term_months = term_years * 12;
    balance = loan_amount;

    // Calculation loop
    for (i = 0; i < term_months; i++) {
        // Interest calculation
        float interest = balance * monthly_interest_rate;
        // Monthly payment calculation
        if (i == term_months - 1) {
            monthly_payment = balance + interest;
        } else {
            monthly_payment = (balance * (monthly_interest_rate * powf((1 + monthly_interest_rate), term_months))) / (powf((1 + monthly_interest_rate), term_months) - 1);
        }
        // Balance calculation
        balance = balance - (monthly_payment - interest);
        // Output payment details
        printf("Month %d:\n", i+1);
        printf("Payment: $%.2f\n", monthly_payment);
        printf("Interest paid: $%.2f\n", interest);
        printf("Balance: $%.2f\n", balance);
    }

    return 0;
}