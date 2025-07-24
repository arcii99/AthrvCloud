//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>

int main() {
  printf("Welcome to the Personal Finance Planner!\n");
  printf("Please enter your monthly income: ");

  float monthlyIncome;
  scanf("%f", &monthlyIncome);

  printf("Great! Now, let's enter your monthly expenses.\n");

  float rent;
  printf("Rent/Mortgage: ");
  scanf("%f", &rent);

  float utilities;
  printf("Utilities: ");
  scanf("%f", &utilities);

  float transportation;
  printf("Transportation: ");
  scanf("%f", &transportation);

  float groceries;
  printf("Groceries: ");
  scanf("%f", &groceries);

  float entertainment;
  printf("Entertainment: ");
  scanf("%f", &entertainment);

  printf("\nHere is a breakdown of your finances:\n");
  printf("------------------------------------\n");

  float totalExpenses = rent + utilities + transportation + groceries + entertainment;
  printf("Total Monthly Expenses: $%.2f\n", totalExpenses);

  float remainingIncome = monthlyIncome - totalExpenses;
  printf("Remaining Income: $%.2f\n", remainingIncome);

  float savingsPercentage = (remainingIncome / monthlyIncome) * 100;
  printf("Savings: %.2f%%\n", savingsPercentage);
  
  printf("\nThank you for using the Personal Finance Planner! Goodbye!");
  
  return 0;
}