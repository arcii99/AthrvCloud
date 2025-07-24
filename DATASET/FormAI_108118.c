//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main()
{
    float loanAmount, interestRate, monthlyPayment, balance;
    int totalMonths, paidMonths;

    // Input loan amount, interest rate and total months
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter total months: ");
    scanf("%d", &totalMonths);

    // Calculate monthly payment using formula
    float monthlyRate = interestRate / 100.0 / 12.0;
    monthlyPayment = loanAmount * monthlyRate / (1 - pow(1 + monthlyRate, -totalMonths));

    // Initialize balance and paid months variables
    balance = loanAmount;
    paidMonths = 0;

    // Print monthly payment
    printf("\nMonthly Payment: $%.2f\n\n", monthlyPayment);

    // Loop through each month and print payment details
    while (balance > 0)
    {
        // Calculate interest and amount paid for the month
        float interest = balance * monthlyRate;
        float amountPaid = monthlyPayment - interest;

        // Update balance and paid months
        balance -= amountPaid;
        paidMonths++;

        // Print payment details for the month
        printf("Month %d:\n", paidMonths);
        printf("\tPayment: $%.2f\n", monthlyPayment);
        printf("\tInterest: $%.2f\n", interest);
        printf("\tAmount Paid: $%.2f\n", amountPaid);
        printf("\tBalance: $%.2f\n\n", balance);
    }

    // Print total months and interest paid
    printf("It took %d months to pay off the loan.\n", paidMonths);
    printf("Total interest paid: $%.2f\n", (paidMonths * monthlyPayment) - loanAmount);

    return 0;
}