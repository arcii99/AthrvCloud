//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: surprised
#include <stdio.h>
#include <math.h>

int main() {
   printf("Welcome to the Mortgage Calculator!\n");

   // Get the loan amount from the user.
   double loanAmount;
   printf("Enter the loan amount: ");
   scanf("%lf", &loanAmount);

   // Get the interest rate from the user.
   double interestRate;
   printf("Enter the interest rate (e.g. 4.5 for 4.5%%): ");
   scanf("%lf", &interestRate);
   interestRate /= 100; // Convert from percentage to decimal.

   // Get the loan term (in years) from the user.
   int loanTerm;
   printf("Enter the loan term (in years): ");
   scanf("%d", &loanTerm);

   // Calculate the number of payments.
   int numPayments = loanTerm * 12;

   // Calculate the monthly interest rate.
   double monthlyInterestRate = interestRate / 12;

   // Calculate the monthly payment using the formula:
   //     M = P * (r * (1 + r)^n) / ((1 + r)^n - 1)
   double mortgagePayment = loanAmount * (monthlyInterestRate * pow(1 + monthlyInterestRate, numPayments)) /
      (pow(1 + monthlyInterestRate, numPayments) - 1);

   // Display the results to the user.
   printf("\nYour monthly mortgage payment is: $%.2lf\n", mortgagePayment);

   printf("Thanks for using the Mortgage Calculator!");

   return 0;
}