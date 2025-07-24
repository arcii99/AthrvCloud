//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: puzzling
#include <stdio.h>
#include <math.h>

int main() {
    float loanAmount, interestRate, monthlyPayment, totalInterest, totalAmount;
    
    printf("Welcome to the Puzzling Mortgage Calculator!\n");
    printf("Enter the loan amount: $");
    scanf("%f", &loanAmount);
    
    printf("\nEnter the interest rate (APR): ");
    scanf("%f", &interestRate);
    
    printf("\nEnter the desired monthly payment: $");
    scanf("%f", &monthlyPayment);
    
    float monthlyRate = (interestRate / 100) / 12;
    float months = ceil(log10(monthlyPayment / (monthlyPayment - (loanAmount * monthlyRate))) / log10(1 + monthlyRate));
    
    totalInterest = (monthlyRate * months * loanAmount) - loanAmount;
    totalAmount = loanAmount + totalInterest;
    
    printf("\n");
    printf("------------------------------------------\n");
    printf("\nHere are the results:\n");
    printf("\n");
    printf("Loan Amount: $%.2f\n", loanAmount);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("\n");
    printf("It will take you %0.0f months to pay off the loan.\n", months);
    printf("Total interest paid: $%.2f\n", totalInterest);
    printf("Total amount paid: $%.2f\n", totalAmount);
    printf("\n");
    printf("------------------------------------------\n");

    return 0;
}