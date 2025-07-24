//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>

int main() {
  float salary, rent, bills, savings, totalExpenses, remaining;

  printf("Welcome to your Personal Finance Planner!\n");
  printf("Please enter your monthly salary: ");
  scanf("%f", &salary);

  printf("Please enter your monthly rent/mortgage payment: ");
  scanf("%f", &rent);

  printf("Please enter your total monthly bills: ");
  scanf("%f", &bills);

  printf("Please enter the percentage of your income you would like to save each month (Enter a value between 0 and 100): ");
  scanf("%f", &savings);

  totalExpenses = rent + bills;
  remaining = salary - totalExpenses;

  printf("\n\n");
  printf("======= Monthly Expenses =======\n");
  printf("Rent/Mortage Payment: $%.2f\n", rent);
  printf("Total Monthly Bills: $%.2f\n", bills);
  printf("Total Monthly Expenses: $%.2f\n", totalExpenses);
  printf("\n\n");

  printf("======= Monthly Savings =======\n");
  printf("Percentage of Income Saved: %.2f%%\n", savings);
  printf("Amount Saved per Month: $%.2f\n", (savings / 100) * salary);
  printf("\n\n");

  printf("======= Remaining Income =======\n");
  printf("Remaining Income After Expenses and Savings: $%.2f\n", remaining);

  return 0;
}