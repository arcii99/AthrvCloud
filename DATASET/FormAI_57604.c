//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   int loanAmt, age, term, interest, monthlyPayment;
   printf("\nWelcome to the Shape Shifting Mortgage Calculator!");

start:
   printf("\n\nPlease enter your loan amount: ");
   scanf("%d", &loanAmt);
   if (loanAmt < 0) {
      printf("\nInvalid input. Please enter a positive number.");
      goto start;
   }

age_input:
   printf("\nPlease enter your age: ");
   scanf("%d", &age);
   if (age < 18) {
      printf("\nYou have to be 18 or older to get a mortgage.");
      goto age_input;
   }

term_input:
   printf("\nPlease enter your mortgage term in years: ");
   scanf("%d", &term);
   if (term < 0) {
      printf("\nInvalid input. Please enter a positive number.");
      goto term_input;
   }

interest_input:
   printf("\nPlease enter your interest rate in percentage: ");
   scanf("%d", &interest);
   if (interest < 0) {
      printf("\nInvalid input. Please enter a positive number.");
      goto interest_input;
   }

   float monthlyInterest = interest / 1200.0;
   int numberOfPayments = term * 12;

   if (monthlyInterest == 0) {
      monthlyPayment = loanAmt / numberOfPayments;
   } else {
      int temp = pow(1 + monthlyInterest, numberOfPayments);
      monthlyPayment = loanAmt * (monthlyInterest * temp) / (temp - 1);
   }

   printf("\nYour monthly payment is $%d", monthlyPayment);

   char yn;
   printf("\n\nWould you like to calculate again? (y/n): ");
   scanf("%s", &yn);
   if (yn == 'y' || yn == 'Y') {
      goto start;
   } else {
      printf("\nThank you for using the Shape Shifting Mortgage Calculator!\n");
   }

return 0;
}