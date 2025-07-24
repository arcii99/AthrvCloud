//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: statistical
#include <stdio.h>
#include <math.h>

int main() {
   float amount;
   float interest;
   int years;
   float monthly_payment;
   float total_interest_paid;
   float total_paid;

   printf("Welcome to the Mortgage Calculator\n\n");

   printf("Enter the amount of the mortgage: ");
   scanf("%f", &amount);

   printf("Enter the interest rate of the mortgage: ");
   scanf("%f", &interest);

   printf("Enter the term of the mortgage in years: ");
   scanf("%d", &years);

   printf("\n");

   interest = interest / 1200; // convert annual interest to monthly

   int months = years * 12; // convert term to months

   monthly_payment = amount * (interest * pow(1 + interest, months)) / (pow(1 + interest, months) - 1);
   total_interest_paid = monthly_payment * months - amount;
   total_paid = monthly_payment * months;

   printf("Monthly Payment: $%.2f\n", monthly_payment);
   printf("Total Interest Paid: $%.2f\n", total_interest_paid);
   printf("Total Paid: $%.2f\n", total_paid);

   return 0;
}