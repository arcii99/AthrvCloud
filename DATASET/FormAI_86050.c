//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: peaceful
#include <stdio.h>
#include <math.h>

int main()
{
    double loanAmount, interestRate, monthlyPayment, totalInterestPaid;
    int years, totalPayments, numMonths;
    
    printf("Welcome to the Peaceful Mortgage Calculator.\n");
    printf("Please enter the following details:\n");
    
    // gather input from user
    printf("Loan amount (in dollars): ");
    scanf("%lf", &loanAmount);
    
    printf("Interest rate (as a percentage): ");
    scanf("%lf", &interestRate);
    
    printf("Number of years for the mortgage: ");
    scanf("%d", &years);
    
    // perform calculation for number of payments
    numMonths = years * 12;
    totalPayments = numMonths;
    
    // calculate monthly interest rate
    interestRate /= 100.0;
    double monthlyInterestRate = interestRate / 12.0;
    
    // calculate monthly payment
    monthlyPayment = loanAmount * (monthlyInterestRate * pow(1 + monthlyInterestRate, totalPayments)) / (pow(1 + monthlyInterestRate, totalPayments) - 1);
    
    // calculate total interest paid
    totalInterestPaid = (monthlyPayment * totalPayments) - loanAmount;
    
    // display results to user
    printf("\n----------------------------\n");
    printf("MORTGAGE DETAILS:\n");
    printf("----------------------------\n");
    printf("Loan amount: $%.2lf\n", loanAmount);
    printf("Interest rate: %.2lf%%\n", interestRate);
    printf("Number of years: %d\n", years);
    printf("Monthly payment: $%.2lf\n", monthlyPayment);
    printf("Total interest paid: $%.2lf\n", totalInterestPaid);
    printf("----------------------------\n");
    
    return 0;
}