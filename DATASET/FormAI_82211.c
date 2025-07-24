//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: immersive
#include <stdio.h>

int main() {
   float loanAmount, interestRate, monthlyPayment, principle, interest, balance;
   int numYears, numMonths, numPayments;

   printf("Welcome to the Mortgage Calculator!\n\n");

   // Get loan amount from user
   printf("Enter the loan amount: $");
   scanf("%f", &loanAmount);

   // Get interest rate from user
   printf("Enter the interest rate: ");
   scanf("%f", &interestRate);

   // Get number of years from user
   printf("Enter the number of years: ");
   scanf("%d", &numYears);

   // Calculate monthly interest rate
   float monthlyInterestRate = interestRate / 1200;

   // Calculate number of payments
   numPayments = numYears * 12;

   // Calculate monthly payment using formula
   monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - (pow(1 + monthlyInterestRate, -numPayments)));

   printf("\nHere is your mortgage summary:\n\n");

   // Print loan details
   printf("Loan amount: $%.2f\n", loanAmount);
   printf("Interest rate: %.2f%%\n", interestRate);
   printf("Number of years: %d\n", numYears);
   printf("Monthly payment: $%.2f\n", monthlyPayment);

   // Print payment schedule
   printf("\nHere is your Payment Schedule:\n\n");

   // Initialize balance to loan amount
   balance = loanAmount;

   // Print headers for payment schedule
   printf("%10s%15s%15s%15s\n", "Payment #", "Interest", "Principle", "Balance");

   // Loop through each payment
   for (int i = 1; i <= numPayments; i++) {
      
      // Calculate interest and principle amounts for current payment
      interest = balance * monthlyInterestRate;
      principle = monthlyPayment - interest;

      balance -= principle;

      // Print payment details
      printf("%10d%15.2f%15.2f%15.2f\n", i, interest, principle, balance);
   }

   printf("\nThank you for using the Mortgage Calculator!\n");

   return 0;
}