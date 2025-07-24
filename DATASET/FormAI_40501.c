//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include<stdio.h>

float interest_calc(float p, float r, int t)
{
   float interest = (p * r * t) / 100.00;
   return interest;
}

int main()
{
   float principal, interest_rate, total_interest, total_amount;
   int time_in_years, i;
   char choice;

   printf("Welcome to Personal Finance Planner\n");

   do
   {
      
      printf("Enter the principal amount: ");
      scanf("%f", &principal);

      printf("Enter the interest rate: ");
      scanf("%f", &interest_rate);

      printf("Enter the time in years: ");
      scanf("%d", &time_in_years);

      total_interest = interest_calc(principal, interest_rate, time_in_years);

      total_amount = principal + total_interest;

      printf("The interest for the given time is %.2f\n", total_interest);

      printf("The total amount after %.d years is %.2f\n", time_in_years, total_amount);

      printf("Do you want to calculate again? (y/n): ");
      scanf("%s", &choice);

   } while (choice == 'y');

   printf("Thank you for using Personal Finance Planner\n");

   return 0;
}