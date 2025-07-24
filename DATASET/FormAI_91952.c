//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare input variables
  float salary, expenses, savings_goal;

  // Get input from user
  printf("Enter your monthly salary: ");
  scanf("%f", &salary);
  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);
  printf("Enter your savings goal: ");
  scanf("%f", &savings_goal);

  // Calculate monthly savings
  float monthly_savings = salary - expenses;

  // Calculate time to reach saving goal
  float time_to_goal = savings_goal / monthly_savings;

  // Print results
  printf("\nMonthly Savings: $%.2f\n", monthly_savings);
  printf("Time to reach savings goal: %.2f months\n", time_to_goal);

  // Check if savings goal is achievable within 5 years
  if (time_to_goal > 60) {
    printf("You may need to adjust your expenses or savings goal to reach your target within 5 years.\n");
  } else {
    printf("You are on track to reach your savings goal within 5 years!\n");
  }

  // Exit program
  return 0;
}