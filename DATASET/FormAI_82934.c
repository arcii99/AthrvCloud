//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>

int main() {
  float salary, expenses, savings;

  printf("Welcome to your Personal Finance Planner!\n");
  printf("Please enter your monthly salary: ");
  scanf("%f", &salary);

  printf("Please enter your monthly expenses: ");
  scanf("%f", &expenses);

  savings = salary - expenses;

  if (savings < 0) {
    printf("Warning: You are spending more than you are making!\n");
  }

  printf("Your monthly savings: $%.2f\n", savings);

  return 0;
}