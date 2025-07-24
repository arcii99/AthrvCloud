//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

int main() {
   double loanAmount, interestRate, years;
   double monthlyPayment, totalPayment;

   printf("Enter loan amount: ");
   scanf("%lf", &loanAmount);

   printf("Enter interest rate (annual): ");
   scanf("%lf", &interestRate);

   printf("Enter loan period in years: ");
   scanf("%lf", &years);

   // Convert interest rate from annual to monthly
   interestRate /= (12 * 100);

   // Calculate monthly payment
   double denominator = pow((1 + interestRate), years * 12) - 1;
   monthlyPayment = (loanAmount * interestRate * pow((1 + interestRate), years * 12)) / denominator;

   // Calculate total payment
   totalPayment = monthlyPayment * years * 12;

   printf("\nLoan amount: $%.2lf\n", loanAmount);
   printf("Interest rate (annual): %.2lf%%\n", interestRate * (12 * 100));
   printf("Loan period (years): %.2lf\n", years);
   printf("Monthly payment: $%.2lf\n", monthlyPayment);
   printf("Total payment: $%.2lf\n", totalPayment);

   return 0;
}