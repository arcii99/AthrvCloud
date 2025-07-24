//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: recursive
#include <stdio.h>

// Recursive function to calculate the mortgage payment
double calculatePayment(double principal, double interestRate, double years, double remainingBalance)
{
   double monthlyInterest = interestRate / 12.0;
   double months = years * 12.0;
   
   if (months == 0.0) {
       return -1.0;
   }
   else if (months == 1.0) {
       return remainingBalance * (1.0 + monthlyInterest);
   } 
   else {
       double monthlyPayment = calculatePayment(principal, interestRate, years - 1.0, remainingBalance);
       double balance = principal * pow((1.0 + monthlyInterest), months - 1) - monthlyPayment * (pow((1.0 + monthlyInterest), months - 1) - 1.0) / monthlyInterest;
       return calculatePayment(principal, interestRate, 1.0, balance);
   }
}

int main()
{
   double principal, interestRate, years, remainingBalance;
   printf("Enter the principal amount: ");
   scanf("%lf", &principal);
   printf("Enter the annual interest rate: ");
   scanf("%lf", &interestRate);
   printf("Enter the duration of mortgage in years: ");
   scanf("%lf", &years);
   remainingBalance = principal;
   
   double monthlyPayment = calculatePayment(principal, interestRate, years, remainingBalance);
   if (monthlyPayment != -1.0) {
       printf("Your monthly mortgage payment is: $%.2lf", monthlyPayment);
   } else {
       printf("Invalid input.");
   }
   
   return 0;
}