//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: systematic
#include <stdio.h>
#include <math.h>

int main() {
    double principal = 0.0, interest_rate = 0.0, years = 0.0, monthly_payment = 0.0;

    // Get the user's input for principal, interest rate, and years.
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the interest rate (e.g. 5.5): ");
    scanf("%lf", &interest_rate);

    printf("Enter the number of years: ");
    scanf("%lf", &years);

    // Calculate the monthly payment based on the user's input.
    double monthly_interest_rate = interest_rate / 1200.0;
    double total_payments = years * 12.0;
    monthly_payment = (principal * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -total_payments));

    // Print out the monthly payment to the user.
    printf("\nYour monthly payment will be: $%.2f\n\n", monthly_payment);

    // Print out a table showing the user's payment schedule.
    printf("Payment Schedule:\n");

    // Calculate the remaining balance for each month and print it out
    double remaining_balance = principal;
    for (int month = 1; month <= total_payments; month++) {
        double monthly_interest = remaining_balance * monthly_interest_rate;
        double principal_payment = monthly_payment - monthly_interest;
        remaining_balance -= principal_payment;
        printf("%d:\t$%.2f\t$%.2f\t$%.2f\n", month, monthly_payment, monthly_interest, principal_payment);
    }

    return 0;
}