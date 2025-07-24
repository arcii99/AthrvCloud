//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

int main() {
    float principal, rate, time;
    float monthly_rate, monthly_payment, total_payment;

    // Get loan principal
    printf("Enter loan principal: ");
    scanf("%f", &principal);

    // Get interest rate
    printf("Enter interest rate per year: ");
    scanf("%f", &rate);

    // Get time
    printf("Enter loan term in years: ");
    scanf("%f", &time);

    // Calculate monthly payment
    monthly_rate = rate / (12 * 100);
    monthly_payment = principal * monthly_rate * pow(1 + monthly_rate, 12 * time)
                      / (pow(1 + monthly_rate, 12 * time) - 1);
    total_payment = monthly_payment * 12 * time;

    // Print results
    printf("\n\nMortgage Payment Calculator\n");
    printf("****************************\n");
    printf("Loan Principal     : $%.2f\n", principal);
    printf("Interest Rate      : %.2f%%\n", rate);
    printf("Loan Term (Years)  : %.2f\n", time);
    printf("Monthly Payment    : $%.2f\n", monthly_payment);
    printf("Total Payment      : $%.2f\n", total_payment);

    return 0;
}