//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: light-weight
#include <stdio.h>

int main() {
    float loan_principal, interest_rate, monthly_payment, balance;
    int term_in_months, months_left = 0;

    // Take user inputs
    printf("Enter loan principal:\n");
    scanf("%f", &loan_principal);

    printf("Enter interest rate:\n");
    scanf("%f", &interest_rate);

    printf("Enter term of loan in months:\n");
    scanf("%d", &term_in_months);

    // Calculate monthly payment
    interest_rate /= 100.0; // Convert to decimal
    monthly_payment = (loan_principal * interest_rate) / (1 - pow(1 + interest_rate, -term_in_months));

    balance = loan_principal;
    printf("\nMonthly payment: $%.2f\n", monthly_payment);

    // Display amortization table
    printf("\nAmortization Table:\n\n");
    printf("Month\tBalance\t\tPayment\t\tInterest\tPrincipal\n");

    for (int i = 1; i <= term_in_months; i++) {
        // Calculate interest and principal
        float interest_payment = balance * interest_rate;
        float principal_payment = monthly_payment - interest_payment;

        // Adjust balance and remaining months
        balance -= principal_payment;
        months_left = term_in_months - i + 1;

        // Print month-wise details in table
        printf("%d\t$%.2f\t\t$%.2f\t\t$%.2f\t\t$%.2f\n", i, balance, monthly_payment, interest_payment, principal_payment);

        // Check if balance is paid off early
        if (balance <= 0) {
            printf("\nLoan paid off in %d months.\n", i);
            break;
        }
    }

    // Check if loan is still unpaid at term end
    if (balance > 0) {
        printf("\nFinal payment: $%.2f\n", balance + (balance * interest_rate));
        printf("Remaining months: %d\n", months_left);
    }

    return 0;
}