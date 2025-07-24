//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ultraprecise
#include<stdio.h>
#include<math.h>
 
int main()
{
    // Variables for user input
    float loanAmt, annualIntRate, monthlyIntRate, numMonths;
    // Variables for calculation
    float monthlyPaymentAmt, totalPaymentAmt;
 
    // Take input from user
    printf("Enter loan amount: ");
    scanf("%f", &loanAmt);
    printf("Enter annual interest rate: ");
    scanf("%f", &annualIntRate);
    printf("Enter number of months: ");
    scanf("%f", &numMonths);
 
    // Calculate monthly interest rate
    monthlyIntRate = annualIntRate / 1200;
 
    // Calculate monthly payment amount
    monthlyPaymentAmt = (loanAmt*monthlyIntRate) / (1 - (pow(1/(1 + monthlyIntRate),numMonths)));
 
    // Calculate total payment amount
    totalPaymentAmt = monthlyPaymentAmt * numMonths;
 
    // Display results
    printf("\n");
    printf("Monthly payment amount: %.2f\n", monthlyPaymentAmt);
    printf("Total payment amount: %.2f\n", totalPaymentAmt);
 
    return 0;
}