//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>

int main(void) {
  float monthlyIncome, rent, groceries, transportation, utilities, savings;
  printf("Enter your monthly income: ");
  scanf("%f", &monthlyIncome);
  printf("Enter your monthly rent: ");
  scanf("%f", &rent);
  printf("Enter your monthly grocery expenses: ");
  scanf("%f", &groceries);
  printf("Enter your monthly transportation expenses: ");
  scanf("%f", &transportation);
  printf("Enter your monthly utility bills expenses: ");
  scanf("%f", &utilities);
  printf("\n");

  // Calculating Total Expenses
  float totalExpenses = rent + groceries + transportation + utilities;
  printf("Your total monthly expenses are: %.2f\n", totalExpenses);

  // Calculating Monthly Savings
  savings = monthlyIncome - totalExpenses;
  printf("Your monthly savings are: %.2f\n", savings);

  // Determining if monthly savings are enough
  if (savings < (monthlyIncome * 0.2)) {
    printf("Your monthly savings are not enough. You need to save more for emergencies and future investments.\n");
  } else {
    printf("Your monthly savings are sufficient. Keep up the good work!\n");
  }

  // Determining if budget allows for entertainment expenses
  float entertainmentBudget = monthlyIncome * 0.1;
  if ((savings + entertainmentBudget) >= totalExpenses) {
    printf("You have enough budget for entertainment this month. Enjoy!\n");
  } else {
    printf("Your monthly budget does not allow for entertainment expenses. Consider cutting back on certain expenses or looking for additional income.\n");
  }

  return 0;
}