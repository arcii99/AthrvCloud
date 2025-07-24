//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

int main() {
   float loanAmount, interestRate, monthlyPayment, totalPayment, principle, interest, balance;
   int loanTerm, numPayments;
   
   printf("Enter the loan amount ($): ");
   scanf("%f", &loanAmount);
   
   printf("Enter the interest rate (%%): ");
   scanf("%f", &interestRate);

   printf("Enter the loan term (years): ");
   scanf("%d", &loanTerm);

   interestRate = interestRate / 1200.0;
   numPayments = loanTerm * 12;

   monthlyPayment = (loanAmount * interestRate) / (1 - pow(1 + interestRate, -numPayments));
   totalPayment = monthlyPayment * numPayments;

   printf("Your monthly payment is: $%.2f\n", monthlyPayment);
   printf("Your total payment is: $%.2f\n", totalPayment);

   printf("\nMonthly Payment Schedule:\n");
   printf("-----------------------------\n");
   printf("          Payment          |\n");
   printf(" Payment |  Principle | Interest  | Balance |\n");

   principle = 0;
   interest = 0;
   balance = loanAmount;

   for (int i = 1; i <= numPayments; i++) {
      interest = balance * interestRate;
      principle = monthlyPayment - interest;
      balance -= principle;
      printf(" %4d   |   $%6.2f  |  $%6.2f  |  $%6.2f |\n", i, principle, interest, balance);
   }

   return 0;
}