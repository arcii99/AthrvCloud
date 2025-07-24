//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>

int main() {
    double loanAmount, interestRate, monthlyPayment, principal, interest, balance;
    int numPayments, i;

    // Get input from user for mortgage details
    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);
    printf("Enter interest rate (percent per year): ");
    scanf("%lf", &interestRate);
    printf("Enter number of payments (months): ");
    scanf("%d", &numPayments);

    // Convert interest rate to monthly decimal
    interestRate /= 1200;

    // Calculate monthly payment
    monthlyPayment = loanAmount * interestRate / (1 - pow(1 + interestRate, -numPayments));

    // Output monthly payment
    printf("Monthly Payment: $%.2f\n", monthlyPayment);

    // Loop through payment periods and calculate payments
    balance = loanAmount;
    for (i = 1; i <= numPayments; i++) {
        interest = balance * interestRate;
        principal = monthlyPayment - interest;
        balance -= principal;
        printf("%5d\t$%8.2f\t$%8.2f\t$%8.2f\n", i, interest, principal, balance);
    }

    return 0;
}