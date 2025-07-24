//FormAI DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>

int main() {
  printf("Welcome to the Expense Tracker Program!\n");

  // Initializing variables
  int expenseAmount = 0;
  int totalExpense = 0;
  int days = 0;

  printf("How many days do you want to track expenses for? ");
  scanf("%d", &days);

  // Preparing to enter expenses for each day
  for (int i = 1; i <= days; i++) {

    printf("\n--- Day %d ---\n", i);

    // Calculating total expense for the day
    printf("Enter your expenses for the day: ");
    scanf("%d", &expenseAmount);
    totalExpense += expenseAmount;

    // Checking if total expense exceeds $100
    if (totalExpense > 100) {
      printf("You have exceeded your daily expense limit of $100\n");
      printf("Please adjust your expenses for the day\n");

      // Adjusting expenses for the day
      printf("Enter your new expenses for the day: ");
      scanf("%d", &expenseAmount);
      totalExpense = expenseAmount;
    }
  }

  // Displaying final total expense
  printf("\nTotal expenses over the %d days: %d\n", days, totalExpense);
  printf("Thank you for using the Expense Tracker Program!\n");

  return 0;
}