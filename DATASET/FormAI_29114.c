//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int loanAmount, termYears, termMonths;
    float interestRate, monthlyPayment, totalInterest, totalPaid;

    printf("Welcome to Sherlock Holmes' Mortgage Calculator!\n");
    printf("Please provide the following information:\n");

    printf("Loan amount: ");
    scanf("%d", &loanAmount);

    printf("Loan term in years: ");
    scanf("%d", &termYears);

    printf("Loan term in months (if any): ");
    scanf("%d", &termMonths);

    printf("Interest rate (as a percentage): ");
    scanf("%f", &interestRate);

    float monthlyRate = interestRate / 1200; // 12 months per year, 100 to convert to decimal

    int totalMonths = termYears * 12 + termMonths;

    monthlyPayment = (loanAmount * monthlyRate) / (1 - pow((1 + monthlyRate), -totalMonths));
    totalPaid = monthlyPayment * totalMonths;
    totalInterest = totalPaid - loanAmount;

    printf("\n");
    printf("Calculated results:\n");
    printf("Monthly payment: %.2f\n", monthlyPayment);
    printf("Total payment: %.2f\n", totalPaid);
    printf("Total interest paid: %.2f\n", totalInterest);

    if (totalInterest < loanAmount * 0.25) {
        printf("\n");
        printf("It seems this loan is relatively low-risk. However, I still advise caution and careful consideration before making any financial commitments.\n");
    } else {
        printf("\n");
        printf("This loan appears to be high-risk. I must urge you to reconsider or seek professional financial advice before proceeding.\n");
    }

    return 0;
}