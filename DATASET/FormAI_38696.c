//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: thoughtful
#include <stdio.h>
#include <math.h>

int main() {
   double principal, interest_rate, monthly_payment, total_interest;
   int years;

   printf("Enter the principal amount: $");
   scanf("%lf", &principal);

   printf("Enter the interest rate: ");
   scanf("%lf", &interest_rate);

   printf("Enter the loan period in years: ");
   scanf("%d", &years);

   double monthly_rate = (interest_rate / 100) / 12;
   int months = years * 12;

   monthly_payment = (principal * monthly_rate * pow((1 + monthly_rate), months)) / (pow((1 + monthly_rate), months) - 1);
   total_interest = (monthly_payment * months) - principal;

   printf("\nMonthly payment: $%.2lf\n", monthly_payment);
   printf("Total interest: $%.2lf\n", total_interest);
   
   return 0;
}