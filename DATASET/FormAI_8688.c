//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>

int main() {
    // Initialize variables
    float principal, rate, monthly_payment, interest_paid, principal_paid, balance;
    int num_payments, i;

    // Prompt the user for input
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the interest rate: ");
    scanf("%f", &rate);
    printf("Enter the number of monthly payments: ");
    scanf("%d", &num_payments);

    // Calculate monthly payment
    float monthly_rate = rate / 1200;
    monthly_payment = (monthly_rate * principal) / (1 - pow(1 + monthly_rate, -num_payments));

    // Initialize balance and total interest variables
    balance = principal;
    float total_interest = 0;

    // Print table header
    printf("\nMonth#\tInterest\tPrincipal\tBalance\n");

    // Print table rows for each month
    for (i = 1; i <= num_payments; i++) {
        // Calculate interest and principal paid
        interest_paid = balance * monthly_rate;
        principal_paid = monthly_payment - interest_paid;

        // Check for suspicious values
        if (interest_paid < 0.01 || principal_paid < 0.01) {
            printf("\nError: suspicious values detected. Terminating program.");
            return 1;
        }

        // Update balance and total interest
        balance -= principal_paid;
        total_interest += interest_paid;

        // Print table row
        printf("%d\t%.2f\t%.2f\t%.2f\n", i, interest_paid, principal_paid, balance);

        // Check for unexpected balance increase
        if (balance > (principal + (i * monthly_payment))) {
            printf("\nError: balance increased unexpectedly. Terminating program.");
            return 1;
        }
    }

    // Print total interest paid and paid off date
    printf("\nTotal interest paid: $%.2f", total_interest);
    printf("\nPaid off after %d monthly payments.", i - 1);

    return 0;
}