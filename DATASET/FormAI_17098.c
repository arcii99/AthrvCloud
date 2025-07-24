//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: optimized
#include <stdio.h>

int main()
{
    float loanAmount, interestRate, monthlyPayment, totalPayment, principal, balance;
    int termMonths, i;

    // Get Loan Amount
    printf("Enter Loan Amount: ");
    scanf("%f", &loanAmount);

    // Get Interest Rate
    printf("Enter Interest Rate (%% per year): ");
    scanf("%f", &interestRate);

    // Get Term (Months)
    printf("Enter Loan Term (months): ");
    scanf("%d", &termMonths);

    // Calculate Monthly Interest Rate
    float monthlyInterestRate = interestRate / 1200;

    // Calculate Monthly Payment and Total Payment
    monthlyPayment = loanAmount * monthlyInterestRate / (1 - 1 / pow(1 + monthlyInterestRate, termMonths));
    totalPayment = monthlyPayment * termMonths;

    // Print Monthly Payment and Total Payment
    printf("\nMonthly Payment: %.2f\n", monthlyPayment);
    printf("Total Payment: %.2f\n", totalPayment);

    // Print Payment Schedule
    printf("\nPayment Schedule:\n");
    printf("%-10s%-15s%-15s%-15s\n", "Month", "Payment", "Principal", "Balance");
    for (i = 1, balance = loanAmount; balance > 0; i++)
    {
        // Calculate Principal and Balance for Current Month
        principal = monthlyPayment - balance * monthlyInterestRate;
        balance -= principal;

        // Print Payment Schedule for Current Month
        printf("%-10d%-15.2f%-15.2f%-15.2f\n", i, monthlyPayment, principal, balance);
    }

    return 0;
}