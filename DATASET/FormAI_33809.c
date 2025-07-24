//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>

int main() {
  //Declare variables for income and expenses
  float income, rent, utilities, groceries, transportation, entertainment, otherExpenses;
  float totalExpenses, remainingMoney;

  //Prompt user to enter income and expenses
  printf("Enter your monthly income: $");
  scanf("%f", &income);
  printf("Enter your monthly rent or mortgage payment: $");
  scanf("%f", &rent);
  printf("Enter your monthly utilities bill: $");
  scanf("%f", &utilities);
  printf("Enter your monthly grocery expenses: $");
  scanf("%f", &groceries);
  printf("Enter your monthly transportation expenses: $");
  scanf("%f", &transportation);
  printf("Enter your monthly entertainment expenses: $");
  scanf("%f", &entertainment);
  printf("Enter any other monthly expenses: $");
  scanf("%f", &otherExpenses);

  //Calculate total expenses and remaining money
  totalExpenses = rent + utilities + groceries + transportation + entertainment + otherExpenses;
  remainingMoney = income - totalExpenses;

  //Print summary of budget
  printf("\nYour monthly budget summary:\n");
  printf("Income: $%.2f\n", income);
  printf("Expenses:\n");
  printf("- Rent/Mortgage: $%.2f\n", rent);
  printf("- Utilities: $%.2f\n", utilities);
  printf("- Groceries: $%.2f\n", groceries);
  printf("- Transportation: $%.2f\n", transportation);
  printf("- Entertainment: $%.2f\n", entertainment);
  printf("- Other: $%.2f\n", otherExpenses);
  printf("Total expenses: $%.2f\n", totalExpenses);
  printf("Remaining money: $%.2f\n", remainingMoney);

  return 0;
}