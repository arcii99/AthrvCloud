//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>

int main() {
  // User inputs for monthly income and expenses
  float monthlyIncome, rent, groceries, utilities, transportation, insurance, otherExpenses;
  printf("Enter your monthly income: ");
  scanf("%f", &monthlyIncome);
  printf("Enter your monthly rent: ");
  scanf("%f", &rent);
  printf("Enter your monthly grocery expense: ");
  scanf("%f", &groceries);
  printf("Enter your monthly utilities expense: ");
  scanf("%f", &utilities);
  printf("Enter your monthly transportation expense: ");
  scanf("%f", &transportation);
  printf("Enter your monthly insurance expense: ");
  scanf("%f", &insurance);
  printf("Enter your other monthly expenses: ");
  scanf("%f", &otherExpenses);

  // Calculate total expense and savings
  float totalExpense = rent + groceries + utilities + transportation + insurance + otherExpenses;
  float savings = monthlyIncome - totalExpense;

  // Display analysis
  printf("Monthly Income: $%.2f\n", monthlyIncome);
  printf("Monthly Expenses:\n");
  printf("   Rent: $%.2f\n", rent);
  printf("   Groceries: $%.2f\n", groceries);
  printf("   Utilities: $%.2f\n", utilities);
  printf("   Transportation: $%.2f\n", transportation);
  printf("   Insurance: $%.2f\n", insurance);
  printf("   Other expenses: $%.2f\n", otherExpenses);
  printf(" Total Expense: $%.2f\n", totalExpense);
  printf("Savings: $%.2f\n", savings);

  // Determine if savings are positive or negative
  if (savings > 0) {
    printf("Congratulations! You are saving money!\n");
  } else if (savings == 0) {
    printf("You are breaking even. Keep up the good work!\n");
  } else {
    printf("Warning: Your expenses are greater than your income. You need to review your spending habits and make some changes to your budget.\n");
  }

  return 0;
}