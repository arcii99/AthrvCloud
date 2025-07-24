//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: single-threaded
#include <stdio.h>

int main() {
    double loanAmount, interestRate, monthlyPayment, balance, interest, principal;
    int months;

    // Get user input
    printf("Enter the loan amount: $");
    scanf("%lf", &loanAmount);

    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);

    printf("Enter the number of months for the loan: ");
    scanf("%d", &months);

    // Calculate monthly payment
    double r = interestRate / 1200; // monthly interest rate
    monthlyPayment = (loanAmount * r) / (1 - pow(1 + r, -months));

    // Print the monthly payment
    printf("\nMonthly Payment: $%.2lf\n", monthlyPayment);

    // Set the balance to the loan amount
    balance = loanAmount;

    // Print the amortization table
    printf("\nAmortization Table\n");
    printf("---------------------\n");
    printf("Month\tBalance\t\tPayment\tInterest\tPrincipal\n");

    for (int i = 1; i <= months; i++) {
        // Calculate the monthly interest and principal
        interest = balance * r;
        principal = monthlyPayment - interest;

        // Subtract the monthly payment from the balance
        balance -= principal;

        // Print the table row
        printf("%d\t$%.2lf\t$%.2lf\t$%.2lf\t$%.2lf\n", i, balance, monthlyPayment, interest, principal);
    }

    return 0;
}