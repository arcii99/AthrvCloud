//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>

int main() {
  float income, savings, expenses, budget;
  int months;

  printf("Enter monthly income: $");
  scanf("%f", &income);
  
  printf("Enter current savings: $");
  scanf("%f", &savings);
  
  printf("Enter monthly expenses: $");
  scanf("%f", &expenses);
  
  printf("Enter number of months for budget plan: ");
  scanf("%d", &months);

  budget = (income - expenses) * months + savings;

  printf("Your total budget for the next %d months is: $%.2f\n", months, budget);

  if (budget > 0) {
    printf("You have a surplus of $%.2f.\n", budget);
  } else if (budget == 0) {
    printf("Your budget is balanced.\n");
  } else {
    printf("You are in a deficit of $%.2f.\n", budget * -1);
  }

  return 0;
}