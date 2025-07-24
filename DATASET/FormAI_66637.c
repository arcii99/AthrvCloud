//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>

int main() {
  float income, expenses, savings;
  printf("Enter your monthly income: $");
  scanf("%f", &income);
  printf("Enter your monthly expenses: $");
  scanf("%f", &expenses);

  savings = income - expenses;

  printf("\nIncome: $%.2f\nExpenses: $%.2f\nSavings: $%.2f\n", income, expenses, savings);

  if (savings > 0) {
    printf("\nYou are living below your means and are on track to achieve your financial goals! Keep it up!\n");
  } else if (savings == 0) {
    printf("\nYou are breaking even every month. Consider finding ways to increase your income or reduce your expenses to begin saving towards your financial goals.\n");
  } else {
    printf("\nYou are spending more than you are earning! This can lead to debt and financial instability. Consider finding ways to increase your income or reduce your expenses to begin saving towards your financial goals.\n");
  }

  return 0;
}