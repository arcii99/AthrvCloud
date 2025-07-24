//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ephemeral
#include <stdio.h>
#include <math.h>

int main() {
    double loanAmount, interestRate, monthlyPayment, balance, interest, principle;
    int numPayments;

    printf("Enter the loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);

    printf("Enter the number of payments: ");
    scanf("%d", &numPayments);

    // Calculating monthly interest rate
    interestRate /= 1200;

    // Calculating monthly payment
    monthlyPayment = loanAmount * (interestRate * pow((1 + interestRate), numPayments)) / (pow((1 + interestRate), numPayments) - 1);

    // Calculating remaining balance, interest and principle for each month
    balance = loanAmount;

    printf("Monthly Payment: $%.2lf\n\n", monthlyPayment);
    printf("Payment\t\tInterest\tPrinciple\tBalance\n");

    for (int i = 1; i <= numPayments; i++) {
        interest = balance * interestRate;
        principle = monthlyPayment - interest;
        balance -= principle;
        printf("%d\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", i, interest, principle, balance);
    }

    return 0;
}