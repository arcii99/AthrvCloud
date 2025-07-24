//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the Mortgage Calculator Program\n");
    
    float loanAmount, interestRate, monthlyPayment;
    int years;
    
    // Get loan amount from user
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);
    
    // Get interest rate from user
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    
    // Convert interest rate to monthly rate
    float monthlyRate = interestRate/1200;
    
    // Get number of years from user
    printf("Enter number of years: ");
    scanf("%d", &years);
    
    // Calculate monthly payment
    monthlyPayment = loanAmount*monthlyRate*pow(1+monthlyRate, years*12)/(pow(1+monthlyRate, years*12)-1);
    
    // Print monthly payment
    printf("Your monthly payment is: $%.2f\n", monthlyPayment);
    
    // Calculate total amount paid
    float totalAmountPaid = monthlyPayment*years*12;
    
    // Calculate total interest paid
    float totalInterestPaid = totalAmountPaid - loanAmount;
    
    // Print total amount paid and total interest paid
    printf("Total amount paid over %d years: $%.2f\n", years, totalAmountPaid);
    printf("Total interest paid over %d years: $%.2f\n", years, totalInterestPaid);
    
    return 0;
}