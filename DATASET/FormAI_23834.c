//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>

int main() {
  float budget, expenses, savings;
  
  printf("Welcome to Personal Finance Planner!\n");
  printf("Please enter your monthly budget: ");
  scanf("%f", &budget);
  printf("Please enter your monthly expenses: ");
  scanf("%f", &expenses);
  
  savings = budget - expenses;
  
  if (savings > 0) {
    printf("Congratulations! You have saved $%.2f this month.\n", savings);
  } else if (savings < 0) {
    printf("Oh no! You have overspent by $%.2f this month.\n", -savings);
  } else {
    printf("You have spent exactly your monthly budget this month.\n");
  }
  
  printf("\n");
  
  printf("Here are some tips to improve your finance next month:\n");
  
  if (budget < 1000) {
    printf("- Consider finding ways to increase your income next month.\n");
  }
  
  if (expenses > budget * 0.5) {
    printf("- Try to reduce your expenses by cancelling unnecessary subscriptions or decreasing spending on entertainment.\n");
  }
  
  if (savings < 0) {
    printf("- Make a plan to pay off any debts or loans next month.\n");
  } else if (savings < budget * 0.2) {
    printf("- Consider saving more each month for emergencies or future investments.\n");
  }
  
  return 0;
}