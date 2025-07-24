//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main() {
    double principal, interest_rate, monthly_payment, balance, monthly_interest_rate;
    int years, months, total_months;

    // Get user input
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the interest rate (e.g. 6.5): ");
    scanf("%lf", &interest_rate);

    printf("Enter the number of years: ");
    scanf("%d", &years);

    // Calculate total months and monthly interest rate
    total_months = years * 12;
    monthly_interest_rate = interest_rate / 1200;

    // Calculate monthly payment amount
    monthly_payment = (monthly_interest_rate * principal) / (1 - pow(1 + monthly_interest_rate, -total_months));

    // Print monthly payment amount
    printf("\nYour monthly payment will be: %.2lf\n", monthly_payment);

    // Print schedule table
    printf("\nPayment Schedule:\n\n");
    printf("Month\t\tBalance\t\tPayment\t\tInterest\tPrincipal\n");
    printf("-----\t\t-------\t\t-------\t\t--------\t--------\n");

    balance = principal;
    for (months = 1; months <= total_months; months++) {
        double interest = balance * monthly_interest_rate;
        double principal_paid = monthly_payment - interest;

        if (balance < monthly_payment) {
            monthly_payment = balance + interest;
            principal_paid = balance;
        }

        balance -= principal_paid;
        printf("%d\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", months, balance, monthly_payment, interest, principal_paid);
    }

    return 0;
}