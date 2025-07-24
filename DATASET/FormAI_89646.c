//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>

int main() {
    float loan_amount, interest_rate, years, monthly_payment, total_payment;

    printf("Welcome to the Mortgage Calculator!\n");
    printf("Please enter the loan amount: $");
    scanf("%f", &loan_amount);
    printf("Please enter the interest rate: ");
    scanf("%f", &interest_rate);
    printf("Please enter the number of years: ");
    scanf("%f", &years);

    // Calculations
    float monthly_rate = (interest_rate / 100) / 12;
    float num_payments = years * 12;
    monthly_payment = (loan_amount * monthly_rate) / (1 - pow(1 + monthly_rate, -num_payments));
    total_payment = monthly_payment * num_payments;

    // Output
    printf("\nYour monthly payment is: $%.2f\n", monthly_payment);
    printf("Your total payment is: $%.2f\n", total_payment);

    return 0;
}