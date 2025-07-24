//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
   float monthly_budget, expenses, savings;
   int num_of_months;
   
   // Get user input
   printf("Enter your monthly budget: ");
   scanf("%f", &monthly_budget);
   
   printf("Enter your total expenses for this month: ");
   scanf("%f", &expenses);
   
   printf("How many months would you like to plan for: ");
   scanf("%d", &num_of_months);
   
   // Calculate savings
   savings = (monthly_budget - expenses) * num_of_months;
   
   // Display results
   printf("\n==============================\n");
   printf("Personal Finance Planner Results\n");
   printf("==============================\n");
   printf("Monthly budget: $%.2f\n", monthly_budget);
   printf("Total expenses: $%.2f\n", expenses);
   printf("Number of months: %d\n", num_of_months);
   printf("Projected savings: $%.2f\n", savings);
   
   return 0;
}