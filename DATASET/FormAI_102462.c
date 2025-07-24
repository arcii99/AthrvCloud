//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: detailed
#include <stdio.h>
#include <math.h>

int main() {
    float principal, interest_rate, monthly_rate, total_payment, monthly_payment;
    int num_payments;

    // Ask user inputs
    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the interest rate (in percentage): ");
    scanf("%f", &interest_rate);

    printf("Enter the number of payments: ");
    scanf("%d", &num_payments);

    // Convert interest rate to monthly rate
    monthly_rate = interest_rate / 1200;

    // Compute monthly payment
    monthly_payment = (monthly_rate * principal) / (1 - pow(1 + monthly_rate, -num_payments));

    // Compute total payment
    total_payment = monthly_payment * num_payments;

    // Display results
    printf("\nMonthly Payment: $%.2f\n", monthly_payment);
    printf("Total Payment: $%.2f\n", total_payment);
    printf("Total Interest Paid: $%.2f\n", total_payment - principal);

    return 0;
}