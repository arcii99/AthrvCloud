//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: irregular
#include <stdio.h>

int main() { 

float loanAmount,interestRate;
int termInYears;

printf("Welcome to the Mortgage Calculator 3000!\n");
printf("Please enter your loan amount (in dollars): ");
scanf("%f", &loanAmount);

printf("\nPlease enter the annual interest rate (in percentage): ");
scanf("%f", &interestRate);

printf("\nPlease enter the term of the loan (in years): ");
scanf("%d", &termInYears);

float monthlyInterestRate = interestRate/1200.0;
float termInMonths = 12 * termInYears;
float monthlyPayment = (loanAmount * monthlyInterestRate * pow(1+monthlyInterestRate, termInMonths))
                       / (pow(1+monthlyInterestRate, termInMonths) - 1);
                       
float totalPayment = monthlyPayment * termInMonths;
float totalInterest = totalPayment - loanAmount;

printf("\nYour monthly payment is: $%.2f", monthlyPayment);
printf("\nYour total payment is: $%.2f", totalPayment);
printf("\nYour total interest is: $%.2f", totalInterest);

return 0; 
}