//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: invasive
#include <stdio.h>
#include <math.h>

int main() {

   double principal, interest_rate, monthly_payment, n, total_interest, total_payment;

   printf("Welcome to Mortgage Calculator!\n");

   printf("Please enter the principal amount in dollars: ");
   scanf("%lf", &principal);

   printf("Please enter the interest rate: ");
   scanf("%lf", &interest_rate);

   printf("Please enter the desired monthly payment: ");
   scanf("%lf", &monthly_payment);

   interest_rate /= 100.0;
   interest_rate /= 12.0;

   n = -(log(1 - (interest_rate * principal) / monthly_payment)) / log(1 + interest_rate);

   total_payment = n * monthly_payment;
   total_interest = total_payment - principal;

   printf("\nIt will take you %.1lf months to pay off your mortgage.\n", ceil(n));
   printf("Your total payment will be $%.2lf.\n", total_payment);
   printf("Your total interest will be $%.2lf.\n", total_interest);

   return 0;
}