//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main() {
   double loanAmount, annualInterestRate, monthlyInterestRate, monthlyPayment;
   int termInYears, termInMonths, totalPayments;
   
   printf("Enter the loan amount: ");
   scanf("%lf", &loanAmount);
   
   printf("Enter the annual interest rate: ");
   scanf("%lf", &annualInterestRate);
   
   printf("Enter the term in years: ");
   scanf("%d", &termInYears);
   
   monthlyInterestRate = annualInterestRate / 1200; //calculating monthly interest rate
   termInMonths = termInYears * 12; // calculating term in months
   totalPayments = termInMonths; // Initializing totalPayments
   
   //Calculating the Monthly Payment
   monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -totalPayments));
   
   printf("Loan Amount: $%.2lf\n", loanAmount);
   printf("Annual Interest Rate: %.2lf%\n", annualInterestRate);
   printf("Term in Years: %d\n", termInYears);
   printf("Monthly Payment: $%.2lf\n", monthlyPayment);
   
   return 0;
}