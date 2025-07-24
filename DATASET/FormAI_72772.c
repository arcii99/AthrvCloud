//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>

int main() {
   float monthly_income, monthly_expenses, savings_goal, total_savings;
   int months_to_goal;

   printf("Welcome to the Personal Finance Planner!\n");
   printf("Let's get started by entering your monthly income: ");
   scanf("%f", &monthly_income);
   printf("Great! Now enter your monthly expenses: ");
   scanf("%f", &monthly_expenses);
   printf("What is your savings goal? ");
   scanf("%f", &savings_goal);

   // Calculate the number of months needed to reach the savings goal
   total_savings=0;
   months_to_goal=0;

   while(total_savings < savings_goal) {
       total_savings += (monthly_income - monthly_expenses);
       months_to_goal++;
   }

   printf("\n*********************************************************\n");
   printf("Based on your monthly income and expenses, it will take %d months to reach your savings goal of $%.2f.\n", months_to_goal, savings_goal);
   printf("Here's a breakdown of how much you'll save each month:\n");

   // Calculate and display the monthly savings required to reach the goal
   float monthly_savings = savings_goal/months_to_goal;
   printf("\t\t$%.2f per month\n", monthly_savings);

   return 0;
}