//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main()
{
    float principal_amount, interest_rate, monthly_payment;
    int n; // the number of monthly payments
    float monthly_interest_rate; 
    float numerator, denominator, remaining_balance;
    int i;

    printf("Enter the principal amount of the loan: ");
    scanf("%f", &principal_amount);
    printf("Enter the interest rate (percent per year): ");
    scanf("%f", &interest_rate);
    printf("Enter the number of monthly payments: ");
    scanf("%d", &n);

    // convert the annual interest rate to a monthly rate
    monthly_interest_rate = interest_rate / 1200;

    // calculate the amount of each monthly payment
    numerator = principal_amount * monthly_interest_rate;
    denominator = 1 - pow(1 + monthly_interest_rate, -n);
    monthly_payment = numerator / denominator;

    printf("\n");
    printf("Principal amount: $%.2f\n", principal_amount);
    printf("Interest rate: %.2f%% per year\n", interest_rate);
    printf("Number of monthly payments: %d\n", n);
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("\n");

    // calculate and display the remaining balance after each monthly payment
    for (i = 1; i <= n; i++) {
        remaining_balance = principal_amount * (pow(1 + monthly_interest_rate, n) - pow(1 + monthly_interest_rate, i - 1)) / (pow(1 + monthly_interest_rate, n) - 1);
        printf("After %d monthly payment(s), remaining balance: $%.2f\n", i, remaining_balance);
    }

    return 0;
}