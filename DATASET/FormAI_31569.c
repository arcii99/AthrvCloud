//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
  float salary, rent, food, transport, bills, savings, total_expenses, net_income;
  int remaining_days;
  printf("\nEnter your monthly salary(in dollars): ");
  scanf("%f", &salary);
  printf("\nEnter your monthly rent(in dollars): ");
  scanf("%f", &rent);
  printf("\nEnter your monthly food expenses(in dollars): ");
  scanf("%f", &food);
  printf("\nEnter your monthly transportation expenses(in dollars): ");
  scanf("%f", &transport);
  printf("\nEnter your monthly bills(in dollars): ");
  scanf("%f", &bills);
  printf("\nEnter the percentage of your salary you want to save: ");
  scanf("%f", &savings);
  total_expenses = rent + food + transport + bills;
  printf("\nTotal monthly expenses: $%.2f\n", total_expenses);
  net_income = salary - total_expenses;
  printf("Net monthly income: $%.2f\n", net_income);
  savings = (savings / 100) * salary;
  printf("\nMonthly savings: $%.2f\n", savings);
  remaining_days = (int)(net_income / 30);
  printf("Remaining daily budget: $%d\n", remaining_days);
  return 0;
}