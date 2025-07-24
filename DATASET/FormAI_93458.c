//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
   float amount, interest_rate, payment;
   int years;

   printf("Welcome to the Mortgage Calculator!\n");
   printf("What is your mortgage amount? ");
   scanf("%f", &amount);

   printf("What is your interest rate? ");
   scanf("%f", &interest_rate);

   printf("How many years is your mortgage? ");
   scanf("%d", &years);

   // Calculate monthly interest rate
   float month_rate = interest_rate / 1200;

   // Calculate number of payments
   int n = years * 12;

   // Calculate monthly payment
   payment = (amount * month_rate) / (1 - (pow(1 + month_rate, -n)));

   printf("Your monthly payment is $%.2f\n", payment);
   printf("You will make a total of %d payments.\n", n);
   printf("Thank you for using the Mortgage Calculator! We hope you enjoy your surreal mortgage.\n");

   return 0;
}