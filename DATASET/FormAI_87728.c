//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program calculates the monthly mortgage payment based on the
 * principal amount, the interest rate and the term in years */

int main() {
    double loanAmount, interestRate, monthlyPayment, totalInterest;
    int loanTerm, numOfPayments;
    
    // get user input
    printf("Enter the loan amount (in dollars): ");
    scanf("%lf", &loanAmount);
    printf("Enter the interest rate (in percentage): ");
    scanf("%lf", &interestRate);
    printf("Enter the loan term (in years): ");
    scanf("%d", &loanTerm);
    
    // convert interest rate to monthly rate and loan term to number of payments
    double monthlyRate = interestRate / (12 * 100);
    numOfPayments = loanTerm * 12;
    
    // calculate monthly payment
    monthlyPayment = (loanAmount * monthlyRate) / (1 - pow(1 + monthlyRate, -numOfPayments));
    
    // calculate total interest paid
    totalInterest = (monthlyPayment * numOfPayments) - loanAmount;
    
    // display results
    printf("\nMonthly Mortgage Payment: $%.2lf\n", monthlyPayment);
    printf("Total Interest Paid: $%.2lf\n", totalInterest);
    
    return 0;
}