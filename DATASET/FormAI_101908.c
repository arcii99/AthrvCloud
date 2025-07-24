//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>

int main() {
  float monthly_income, monthly_expenses, savings_goal;
  
  // Get user inputs
  printf("Enter your monthly income: ");
  scanf("%f", &monthly_income);
  
  printf("Enter your monthly expenses: ");
  scanf("%f", &monthly_expenses);
  
  printf("Enter your desired savings goal: ");
  scanf("%f", &savings_goal);
  
  // Calculate how much to save per month to reach goal in 1 year
  float total_savings_goal = savings_goal * 12;
  float monthly_savings_needed = total_savings_goal / 12;
  
  // Calculate monthly surplus/deficit
  float monthly_surplus = monthly_income - monthly_expenses - monthly_savings_needed;
  
  // Display results
  printf("You need to save %.2f per month to reach your savings goal in one year.\n", monthly_savings_needed);
  if (monthly_surplus > 0) {
    printf("You have a surplus of %.2f each month.\n", monthly_surplus);
  } else if (monthly_surplus == 0) {
    printf("You break even each month. No surplus or deficit.\n");
  } else {
    printf("You have a deficit of %.2f each month. Consider cutting expenses or finding ways to increase income.\n", -1 * monthly_surplus);
  }

  return 0;
}