//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Cyberpunk
#include <stdio.h>

int main() {
    float loanAmount, interestRate, monthlyPayment;
    int loanTerm;

    printf("Enter loan amount:");
    scanf("%f", &loanAmount);

    printf("Enter interest rate:");
    scanf("%f", &interestRate);

    printf("Enter loan term (in years):");
    scanf("%d", &loanTerm);

    float monthlyInterest = interestRate / 100 / 12;
    int totalPayableMonths = loanTerm * 12;

    monthlyPayment = (loanAmount * monthlyInterest) / (1 - pow(1 + monthlyInterest, -totalPayableMonths));

    printf("\n");
    printf("\t===============================\n");
    printf("\t\tMORTGAGE CALCULATOR\n");
    printf("\t===============================\n\n");

    printf("Loan amount:\t\t\t%.2f\n", loanAmount);
    printf("Interest rate:\t\t\t%.2f%%\n", interestRate);
    printf("Loan term:\t\t\t%d years\n", loanTerm);
    printf("Monthly payment:\t\t%.2f\n", monthlyPayment);
    printf("Total payable amount:\t\t%.2f\n", monthlyPayment * totalPayableMonths);
    printf("Interest payable amount:\t%.2f\n", (monthlyPayment * totalPayableMonths) - loanAmount);

    return 0;
}