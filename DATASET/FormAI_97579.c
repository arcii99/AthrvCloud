//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to Happy Finance Planner!\n");
  printf("Let's plan your finances for the next 12 months!\n");

  // Declare variables for income and expenses
  float income_monthly, expenses_monthly;
  float income_yearly = 0, expenses_yearly = 0;
  float savings_yearly;

  // Get user input for monthly income and expenses
  for(int i = 1; i <= 12; i++) {
    printf("\nMonth %d:\n", i);
    printf("Enter your monthly income: $");
    scanf("%f", &income_monthly);
    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses_monthly);

    // Add monthly income and expenses to yearly totals
    income_yearly += income_monthly;
    expenses_yearly += expenses_monthly;
  }

  // Calculate yearly savings
  savings_yearly = income_yearly - expenses_yearly;

  // Display yearly summary
  printf("\nYour summary for the year:\n");
  printf("Total yearly income: $%.2f\n", income_yearly);
  printf("Total yearly expenses: $%.2f\n", expenses_yearly);
  printf("Yearly savings: $%.2f\n", savings_yearly);

  // Check if savings are positive, negative, or zero
  if(savings_yearly > 0) {
    printf("Congratulations, you have a surplus of $%.2f for the year!\n", savings_yearly);
  } else if(savings_yearly < 0) {
    printf("Uh-oh, you have a deficit of $%.2f for the year. Consider reducing expenses or increasing income.\n", -savings_yearly);
  } else {
    printf("You broke even for the year. Getting your personal finances on track takes time and diligence, but it's worth it in the end.\n");
  }

  printf("\nThank you for using Happy Finance Planner. Have a great day!\n");

  return 0;
}