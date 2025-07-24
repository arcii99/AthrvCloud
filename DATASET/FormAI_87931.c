//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: satisfied
#include <stdio.h>

int main() {
   float loanAmount, interestRate, monthlyPayment, totalPayment;
   int numberOfMonths;

   printf("Enter the loan amount: ");
   scanf("%f", &loanAmount);

   printf("Enter the interest rate: ");
   scanf("%f", &interestRate);

   printf("Enter the number of months: ");
   scanf("%d", &numberOfMonths);

   interestRate /= 100.0;
   monthlyPayment = (loanAmount * interestRate) / (1 - pow(1 + interestRate, -numberOfMonths));
   totalPayment = monthlyPayment * numberOfMonths;

   printf("\nMonthly Payment: %.2f\n", monthlyPayment);
   printf("Total Payment: %.2f\n", totalPayment);

   return 0;
}