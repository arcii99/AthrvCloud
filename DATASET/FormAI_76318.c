//FormAI DATASET v1.0 Category: Arithmetic ; Style: content
// Arithmetic program to calculate interest earned in a bank account
#include <stdio.h>

int main()
{
    // declare variables
    float principal, rate, time, interest, total_amount;

    // input principal amount
    printf("Enter the principal amount: $");
    scanf("%f", &principal);

    // input interest rate
    printf("Enter the interest rate %% per year: ");
    scanf("%f", &rate);

    // convert interest rate into decimal
    rate = rate / 100;

    // input time period
    printf("Enter the time period (in years): ");
    scanf("%f", &time);

    // calculate interest earned
    interest = principal * rate * time;

    // calculate total amount
    total_amount = principal + interest;

    // output results
    printf("\n\nInterest earned      = $%.2f", interest);
    printf("\nTotal amount earned = $%.2f", total_amount);

    return 0;
}