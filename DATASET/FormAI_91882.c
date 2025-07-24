//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: sophisticated
#include <stdio.h>
#include <math.h>

int main() {
   double loanAmount, interestRate, monthlyPayment, totalPayment, balance;
   int numMonths, i;
   
   printf("Enter the loan amount: $");
   scanf("%lf", &loanAmount);
   
   printf("Enter the interest rate (as a percentage): ");
   scanf("%lf", &interestRate);
   
   printf("Enter the number of months: ");
   scanf("%d", &numMonths);
   
   interestRate /= 1200; // convert to monthly interest rate
   
   monthlyPayment = (loanAmount * interestRate) / (1 - pow(1 + interestRate, -numMonths));
   printf("Monthly payment: $%.2lf\n", monthlyPayment);
   
   totalPayment = monthlyPayment * numMonths;
   printf("Total payment: $%.2lf\n", totalPayment);
   
   balance = loanAmount;
   printf("\nPayment#\tMonthly Payment\tBalance\n");
   
   for(i = 1; i <= numMonths; i++) {
      double interest = balance * interestRate;
      double principal = monthlyPayment - interest;
      balance -= principal;
      
      printf("%d\t\t$%.2lf\t\t$%.2lf\n", i, monthlyPayment, balance);
   }
   
   return 0;
}