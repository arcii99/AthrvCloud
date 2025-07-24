//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scalable
#include <stdio.h>
#include <math.h>

double calculateMortgage(double principal, double interestRate, int loanTerm);

int main() {

   double principal, interestRate;
   int loanTerm;
   
   printf("Enter principal amount: $");
   scanf("%lf",&principal);

   printf("Enter interest rate: ");
   scanf("%lf",&interestRate);
   interestRate = interestRate / 1200.0;

   printf("Enter loan term(in months): ");
   scanf("%d",&loanTerm);

   double monthlyPayment = calculateMortgage(principal, interestRate, loanTerm);
   printf("Monthly Payment: $%.2f\n", monthlyPayment);

   return 0;
}

/**
 * This function takes in three parameters, namely `principal`, `interestRate`, and `loanTerm` 
 * and returns the monthly mortgage payment for a given mortgage.
 */
double calculateMortgage(double principal, double interestRate, int loanTerm) {
   double monthlyPayment;

   monthlyPayment = (principal * interestRate) / (1 - pow(1 + interestRate, -loanTerm));

   return monthlyPayment;
}