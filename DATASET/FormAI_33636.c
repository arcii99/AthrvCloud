//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: thoughtful
#include <stdio.h>
#include <math.h>

int main() {
   float principal, interest_rate, monthly_payment, total_interest;
   int num_months;

   printf("Enter principal: ");
   scanf("%f", &principal);

   printf("Enter interest rate: ");
   scanf("%f", &interest_rate);

   printf("Enter number of months: ");
   scanf("%d", &num_months);

   // Convert percentage interest rate to decimal
   interest_rate /= 100;

   // Calculate monthly interest rate and monthly payment
   float monthly_interest_rate = interest_rate / 12;
   monthly_payment = (principal * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -num_months));

   printf("Monthly payment: $%.2f\n", monthly_payment);

   // Calculate total interest paid
   total_interest = monthly_payment * num_months - principal;
   printf("Total interest paid: $%.2f\n", total_interest);

   return 0;
}