//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: brave
#include <stdio.h>

int main() {
  printf("------------------------\n");
  printf("| Personal Finance Plan |\n");
  printf("------------------------\n");

  int income, expenses, savings, investment;

  printf("Enter your monthly income: $");
  scanf("%d", &income);

  printf("Enter your monthly expenses: $");
  scanf("%d", &expenses);

  printf("Enter the percentage of your income you want to save: ");
  int save_percentage;
  scanf("%d", &save_percentage);

  savings = (income * save_percentage) / 100;
  investment = income - expenses - savings;

  printf("\n------------------------\n");
  printf("Here's your personal finance plan:\n");
  printf("------------------------\n");
  printf("Monthly Income: $%d\n", income);
  printf("Monthly Expenses: $%d\n", expenses);
  printf("Monthly Savings: $%d\n", savings);
  printf("Monthly Investment: $%d\n", investment);

  if (investment > expenses * 2) {
    printf("\nCongrats! You are investing more than twice your expenses. Keep it up!\n");
  } else if (investment > expenses) {
    printf("\nNice job! You are investing more than your expenses. Consider increasing your investment.\n");
  } else {
    printf("\nUh oh! You are spending more than you earn. Consider reducing your expenses and increasing your income.\n");
  }

  return 0;
}