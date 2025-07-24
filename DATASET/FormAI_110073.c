//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
   double principal, rate, years, monthlyPayment, totalInterest, totalPayment;
   
   // Read the input from user
   printf("Enter principal amount: ");
   scanf("%lf", &principal);

   printf("Enter interest rate: ");
   scanf("%lf", &rate);

   printf("Enter the number of years: ");
   scanf("%lf", &years);
  
   // Calculate the monthly interest rate and the number of monthly payments
   double monthlyRate = rate / 1200; 
   double numPayments = years * 12;
   
   // Calculate the monthly payment
   monthlyPayment = (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -numPayments));
   
   // Calculate the total interest and total payment
   totalInterest = (monthlyPayment * numPayments) - principal;
   totalPayment = monthlyPayment * numPayments;
   
   // Display the details of the mortgage
   printf("\nMortgage Details\n");
   printf("Principal amount: $%.2f\n", principal);
   printf("Interest rate: %.2f%%\n", rate);
   printf("Number of years: %.0f\n", years);
   printf("Monthly payment: $%.2f\n", monthlyPayment);
   printf("Total interest paid: $%.2f\n", totalInterest);
   printf("Total payment: $%.2f\n", totalPayment);
   
   return 0;
}