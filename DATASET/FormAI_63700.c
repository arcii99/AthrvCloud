//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to your Personal Finance Planner!\n");
  printf("Let's get started.\n\n");

  double income, rent, bills, groceries, entertainment, savings;
  printf("Enter your monthly income: ");
  scanf("%lf", &income);

  printf("Enter your monthly rent or mortgage payment: ");
  scanf("%lf", &rent);

  printf("Enter your monthly bills (utilities, phone, internet, etc.): ");
  scanf("%lf", &bills);

  printf("Enter your monthly grocery expenses: ");
  scanf("%lf", &groceries);

  printf("Enter your monthly entertainment expenses: ");
  scanf("%lf", &entertainment);

  printf("Enter your planned savings amount: ");
  scanf("%lf", &savings);

  double totalExpenses = rent + bills + groceries + entertainment;
  double totalSavings = savings;
  double netIncome = income - totalExpenses - totalSavings;

  printf("\nHere is your monthly financial summary:\n");
  printf("Total Income: $%.2lf\n", income);
  printf("Total Expenses: $%.2lf\n", totalExpenses);
  printf("Total Savings: $%.2lf\n", totalSavings);
  printf("Net Income: $%.2lf\n", netIncome);

  if (netIncome > 0) {
    printf("\nCongratulations, you have a positive net income!\n");
  } else if (netIncome == 0) {
    printf("\nYour expenses and savings are equal to your income. You're living within your means!\n");
  } else {
    printf("\nUh oh, you have a negative net income. It might be time to re-evaluate your expenses or find ways to increase your income.\n");
  }

  return 0; 
}