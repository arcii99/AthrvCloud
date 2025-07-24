//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: rigorous
#include <stdio.h>
#include <math.h>

int main() {
    float principal, interest_rate, monthly_rate, total_payment;
    int loan_years, total_months, total_payments;
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the interest rate (APR): ");
    scanf("%f", &interest_rate);
    printf("Enter the loan term in years: ");
    scanf("%d", &loan_years);
    // Calculate monthly interest rate and total months
    monthly_rate = interest_rate / 1200;
    total_months = loan_years * 12;
    // Calculate total payment
    float numerator = pow((1 + monthly_rate), total_months) - 1;
    float denominator = monthly_rate * pow((1 + monthly_rate), total_months);
    total_payment = principal * (numerator / denominator);
    // Calculate total payments
    total_payments = total_months;
    printf("Total payment: $%.2f\n", total_payment);
    printf("Total payments: %d\n", total_payments);
    return 0;
}