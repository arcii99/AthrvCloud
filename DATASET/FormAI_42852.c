//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
#include <stdio.h>

int main() {
  float income, expenses, savings;

  printf("Enter your monthly income: ");
  scanf("%f", &income);

  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);

  savings = income - expenses;

  printf("Your monthly savings: $%.2f\n", savings);

  return 0;
}