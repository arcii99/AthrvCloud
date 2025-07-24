//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
// Ada's Personal Finance Planner program

#include <stdio.h>

int main() {
  float salary, rent, groceries, utilities, transportation, other_expenses;
  float savings, expenses, balance;

  // Get user input
  printf("Welcome to Ada's Personal Finance Planner!\n\n");
  printf("Please enter your monthly salary: ");
  scanf("%f", &salary);
  printf("Please enter your monthly rent: ");
  scanf("%f", &rent);
  printf("Please enter your monthly grocery expenses: ");
  scanf("%f", &groceries);
  printf("Please enter your monthly utilities expenses: ");
  scanf("%f", &utilities);
  printf("Please enter your monthly transportation expenses: ");
  scanf("%f", &transportation);
  printf("Please enter your other monthly expenses: ");
  scanf("%f", &other_expenses);

  // Calculate savings and expenses
  expenses = rent + groceries + utilities + transportation + other_expenses;
  savings = salary - expenses;
  balance = savings - (expenses/2);

  // Display results
  printf("\nYour total monthly expenses are: %.2f\n", expenses);
  printf("Your monthly savings are: %.2f\n", savings);
  printf("Your monthly balance after saving half of your expenses: %.2f\n", balance);

  return 0;
}