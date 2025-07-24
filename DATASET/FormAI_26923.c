//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: protected
#include <stdio.h>

int main()
{
    float loanAmount, interestRate, monthlyPayment, totalPayment, totalInterest;
    int numOfYears, numOfMonths;
    
    // Getting user inputs
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);
    
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    interestRate = interestRate / 100.0;
    
    printf("Enter number of years: ");
    scanf("%d", &numOfYears);
    numOfMonths = numOfYears * 12;
    
    // Calculating monthly payment
    monthlyPayment = loanAmount * interestRate * (pow((1 + interestRate), numOfMonths)) / (pow((1 + interestRate), numOfMonths) - 1);
    
    // Calculating total payment and total interest
    totalPayment = monthlyPayment * numOfMonths;
    totalInterest = totalPayment - loanAmount;
    
    // Displaying output
    printf("\n");
    printf("Loan amount: $%.2f\n", loanAmount);
    printf("Interest rate: %.2f %%\n", (interestRate * 100.0));
    printf("Number of years: %d\n", numOfYears);
    printf("-----------------------\n");
    printf("Monthly payment: $%.2f\n", monthlyPayment);
    printf("Total payment: $%.2f\n", totalPayment);
    printf("Total interest: $%.2f\n", totalInterest);
    
    return 0;
}