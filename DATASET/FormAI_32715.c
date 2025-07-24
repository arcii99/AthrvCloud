//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    float loanAmount, annualInterestRate, monthlyInterestRate, monthlyPayment, remainingBalance;
    int loanTerm, numMonth, i;

    printf("Welcome to Mortgage Calculator\n");

    // get loan amount
    printf("Enter Loan Amount: ");
    scanf("%f", &loanAmount);

    // get annual interest rate
    printf("Enter Annual Interest Rate (%): ");
    scanf("%f", &annualInterestRate);

    // get loan term
    printf("Enter Loan Term (in years): ");
    scanf("%d", &loanTerm);

    // calculate monthly interest rate
    monthlyInterestRate = annualInterestRate / 1200;

    // calculate number of months
    numMonth = loanTerm * 12;

    // calculate monthly payment
    monthlyPayment = loanAmount * (monthlyInterestRate * pow(1 + monthlyInterestRate, numMonth)) / (pow(1 + monthlyInterestRate, numMonth) - 1);

    printf("\n\n------------------------------");
    printf("\n\tMORTGAGE SUMMARY");
    printf("\n------------------------------");
    printf("\nLoan Amount (RM)\t: %.2f", loanAmount);
    printf("\nInterest Rate (%% p.a.)\t: %.2f", annualInterestRate);
    printf("\nLoan Term (Year)\t: %d", loanTerm);
    printf("\n------------------------------");
    printf("\nMONTHLY REPAYMENT\t: %.2f", monthlyPayment);
    printf("\n------------------------------");
    printf("\nYEAR\t\t\tPRINCIPAL\tINTEREST\tBALANCE");

    remainingBalance = loanAmount;

    for (i = 1; i <= numMonth; i++) {

        float monthlyInterest = remainingBalance*monthlyInterestRate;
        float principal = monthlyPayment - monthlyInterest;

        remainingBalance = remainingBalance - principal;

        // print yearly info
        if (i % 12 == 0) {
            int year = i / 12;
            printf("\n%d\t\t\t%.2f\t\t%.2f\t\t%.2f", year, principal*12, monthlyInterest*12, remainingBalance);
        }
    }

    printf("\n\nThank you for using Mortgage Calculator.\n");

    return 0;
}