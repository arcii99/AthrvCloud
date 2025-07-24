//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
#include <stdio.h>

float monthly_budget;
float monthly_expenses;
float monthly_income;

int main()
{
  printf("Enter your monthly budget: ");
  scanf("%f", &monthly_budget);

  printf("Enter your monthly expenses: ");
  scanf("%f", &monthly_expenses);

  printf("Enter your monthly income: ");
  scanf("%f", &monthly_income);

  float savings = monthly_income - monthly_expenses;
  float spending_limit = monthly_budget - monthly_expenses;
  
  printf("\n\nMonthly Report:\n");
  printf("Monthly Budget: %.2f\n", monthly_budget);
  printf("Monthly Expenses: %.2f\n", monthly_expenses);
  printf("Monthly Income: %.2f\n", monthly_income);
  printf("Savings: %.2f\n", savings);
  printf("Spending Limit: %.2f\n", spending_limit);

  if (savings > 0)
  {
    printf("\nYou are saving money this month. Good job!\n");
  }
  else
  {
    printf("\nYou are spending more than you're earning. Time to adjust your budget!\n");
    float additional_savings = spending_limit - savings;
    printf("To get back on track, you need to save an additional %.2f this month.\n", additional_savings);
  }

  return 0;
}