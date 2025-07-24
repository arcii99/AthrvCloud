//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: accurate
#include <stdio.h>

int main() {
    float loanAmount, interestRate, monthlyPayment, totalPayment, principalAmount, remainingBalance;
    int termInMonths, i;

    // Get necessary input from user
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);

    printf("Enter interest rate: ");
    scanf("%f", &interestRate);

    printf("Enter term in months: ");
    scanf("%d", &termInMonths);

    // Convert interest rate to monthly rate
    interestRate /= 100.0;
    interestRate /= 12.0;

    // Calculate monthly payment
    monthlyPayment = (loanAmount * interestRate) / (1 - pow(1 + interestRate, -termInMonths));

    // Initialize variables for loop
    principalAmount = loanAmount;
    totalPayment = 0;

    // Print table header
    printf("\nMonth\tPayment\tPrincipal\tInterest\tBalance\n");

    for (i = 1; i <= termInMonths; i++) {
        // Calculate interest for the month
        float interest = principalAmount * interestRate;

        // Calculate amount paid towards principal
        float principalPaid = monthlyPayment - interest;

        // Calculate remaining balance
        remainingBalance = principalAmount - principalPaid;

        // Update total payment
        totalPayment += monthlyPayment;

        // Print the payment information for the month
        printf("%d\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n", i, monthlyPayment, principalPaid, interest, remainingBalance);

        // Update principal amount for next month
        principalAmount = remainingBalance;
    }

    // Print final information
    printf("\nTotal payment: %.2f\n", totalPayment);

    return 0;
}