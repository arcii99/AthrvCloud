//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: minimalist
#include <stdio.h>

int main() {
    float loan_amount, interest_rate, monthly_payment;
    int loan_years;
    float monthly_interest_rate, total_interest, total_payment;

    printf("Enter loan amount: ");
    scanf("%f", &loan_amount);
    printf("Enter interest rate in percentage: ");
    scanf("%f", &interest_rate);
    printf("Enter loan duration in years: ");
    scanf("%d", &loan_years);

    // Calculate monthly interest rate
    monthly_interest_rate = interest_rate / 1200;

    // Calculate monthly payment
    monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -12 * loan_years));
    printf("Monthly payment: $%.2f\n", monthly_payment);

    // Calculate total payment and total interest paid
    total_payment = monthly_payment * loan_years * 12;
    total_interest = total_payment - loan_amount;
    printf("Total payment: $%.2f\n", total_payment);
    printf("Total interest paid: $%.2f\n", total_interest);

    return 0;
}