//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>
#include <math.h>

int main()
{
    float loanAmount, interestRate, monthlyPayment, totalPayment, monthlyInterestRate;
    int months;
    
    // Read values from user input
    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);
    
    printf("Enter the interest rate: ");
    scanf("%f", &interestRate);
    
    printf("Enter the number of months: ");
    scanf("%d", &months);
    
    // Calculate monthly interest rate
    monthlyInterestRate = interestRate / 1200;
    
    // Calculate monthly payment
    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -months));
    
    // Calculate total payment
    totalPayment = monthlyPayment * months;
    
    // Display results
    printf("\nLoan Amount: $%.2f\n", loanAmount);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Number of Months: %d\n", months);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payment: $%.2f\n", totalPayment);
    
    return 0;
}