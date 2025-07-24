//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: detailed
#include <stdio.h>
#include <math.h>

int main() {
   double principal, rate, years;
   double monthly_payment, total_payment, total_interest;

   printf("Welcome to the Mortgage Calculator\n");

   printf("Enter the loan amount (Principal): ");
   scanf("%lf", &principal);

   printf("Enter the annual interest rate (e.g. 5.5 for 5.5%%): ");
   scanf("%lf", &rate);
   rate /= 1200.0;

   printf("Enter the number of years for repayment: ");
   scanf("%lf", &years);
   years *= 12;

   monthly_payment = principal * rate / (1 - pow(1 + rate, -years));
   total_payment = monthly_payment * years;
   total_interest = total_payment - principal;

   printf("\n");
   printf("The monthly payment is $%.2lf\n", monthly_payment);
   printf("The total payment over %g years is $%.2lf\n", years/12, total_payment);
   printf("The total interest over %g years is $%.2lf\n", years/12, total_interest);

   return 0;
}