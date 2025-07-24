//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: accurate
#include <stdio.h>
#include <math.h>

int main()
{
   float mortgageAmount, interestRate, payment, totalInterest;
   int years;
   
   printf("Enter mortgage amount: ");
   scanf("%f", &mortgageAmount);
   printf("Enter interest rate: ");
   scanf("%f", &interestRate);
   printf("Enter number of years: ");
   scanf("%d", &years);
   
   // Calculate monthly interest rate
   float monthlyRate = interestRate/100/12;
   
   // Calculate number of payments
   int numPayments = years*12;
   
   // Calculate mortgage payment
   payment = (mortgageAmount * monthlyRate * pow(1+monthlyRate, numPayments))/(pow(1+monthlyRate, numPayments) - 1);
   
   // Calculate total interest paid
   totalInterest = payment*numPayments - mortgageAmount;
   
   // Display results
   printf("\nMortgage Amount: $%.2f\n", mortgageAmount);
   printf("Interest Rate: %.2f%%\n", interestRate);
   printf("Number of Years: %d\n", years);
   printf("Monthly Payment: $%.2f\n", payment);
   printf("Total Interest Paid: $%.2f\n", totalInterest);
   
   return 0;
}