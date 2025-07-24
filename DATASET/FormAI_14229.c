//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Cyberpunk
#include <stdio.h>

int main() {
    float loanAmount;
    float interestRate;
    float loanTerm;
    float monthlyPayment;

    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter loan term in years: ");
    scanf("%f", &loanTerm);

    // Calculate monthly interest rate
    float monthlyInterestRate = interestRate / 1200;

    // Calculate monthly payment
    monthlyPayment = loanAmount * monthlyInterestRate / (1 - (float)pow(1 + monthlyInterestRate, -12 * loanTerm));

    printf("-------------------\n");
    printf("    CyberPunk Bank \n");
    printf("-------------------\n");
    printf("Loan Amount:\t %.2f\n", loanAmount);
    printf("Interest Rate:\t %.2f%%\n", interestRate);
    printf("Loan Term:\t %.0f years\n", loanTerm);
    printf("Monthly Payment:\t $%.2f\n", monthlyPayment);
    printf("\n\nWelcome to the CyberPunk family.\n\n");

    return 0;
}