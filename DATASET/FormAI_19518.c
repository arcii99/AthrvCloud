//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: secure
#include <stdio.h>
#include <math.h>

int main() {
    double loan_amount, interest_rate, monthly_payment;
    int years;

    printf("Enter loan amount: ");
    scanf("%lf", &loan_amount);
    printf("Enter annual interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter number of years: ");
    scanf("%d", &years);

    // Convert interest rate to monthly rate and years to months
    double monthly_rate = interest_rate / 1200.0;
    int months = years * 12;

    // Calculate monthly payment
    monthly_payment = loan_amount * (monthly_rate * pow(1 + monthly_rate, months)) / (pow(1 + monthly_rate, months) - 1);

    // Print amortization table
    printf("\nMonthly Payment: $%.2f\n\n", monthly_payment);
    printf("Payment#\t\tInterest\t\tPrincipal\t\tBalance\n");

    double balance = loan_amount;
    double interest, principal;

    for (int i = 1; i <= months; i++) {
        interest = balance * monthly_rate;
        principal = monthly_payment - interest;
        balance -= principal;

        printf("%d\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f\n", i, interest, principal, balance);

        // Final payment, round up to ensure balance is zero
        if (i == months && balance > 0) {
            principal += balance;
            monthly_payment = interest + principal;
            balance = 0;
            printf("%d\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f\n", i, interest, principal, balance);
        }
    }

    return 0;
}