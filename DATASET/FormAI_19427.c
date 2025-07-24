//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>
#include <math.h>

int main()
{
    float loan_amount, rate, monthly_rate, monthly_payment, balance;
    int years, months, total_months;

    // Get user inputs
    printf("Enter loan amount: ");
    scanf("%f", &loan_amount);
    printf("Enter annual interest rate: ");
    scanf("%f", &rate);
    printf("Enter loan duration in years: ");
    scanf("%d", &years);

    // Calculate monthly interest rate and total months
    monthly_rate = rate / 1200;
    total_months = years * 12;

    // Calculate monthly payment using formula
    monthly_payment = (loan_amount * monthly_rate) / (1 - pow(1 + monthly_rate, -total_months));

    // Print the result
    printf("\nLoan amount: $%.2f\n", loan_amount);
    printf("Annual interest rate: %.2f%% \n", rate);
    printf("Loan term: %d years\n", years);
    printf("Monthly payment: $%.2f\n", monthly_payment);

    // Display each payment and the remaining balance
    printf("Payment#\tPayment\t\tBalance\n");
    printf("--------\t-------\t\t-------\n");

    for (int i = 1; i <= total_months; i++) {
        // Calculate remaining balance
        balance = loan_amount * pow(1 + monthly_rate, i) - monthly_payment * (pow(1 + monthly_rate, i) - 1) / monthly_rate;

        // Print each payment and balance
        printf("%d\t\t$%.2f\t\t$%.2f\n", i, monthly_payment, balance);
    }

    return 0;
}