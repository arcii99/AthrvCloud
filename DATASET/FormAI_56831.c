//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>

int main() {
  float income, expenses, savings;
  
  // Prompt user to enter income
  printf("Enter your total income: $");
  scanf("%f", &income);
  
  // Prompt user to enter expenses
  printf("Enter your total expenses: $");
  scanf("%f", &expenses);
  
  // Calculate savings
  savings = income - expenses;
  
  // Print results
  printf("Your total income is: $%.2f\n", income);
  printf("Your total expenses are: $%.2f\n", expenses);
  printf("Your total savings are: $%.2f\n", savings);
  
  // Determine whether user is saving enough or not
  if(savings < 0) {
    printf("You are spending more than you earn. Consider reducing your expenses.\n");
  } else if(savings < income*0.2) {
    printf("You are saving less than 20%% of your income. Consider increasing your savings rate.\n");
  } else {
    printf("You are saving at least 20%% of your income. Keep up the good work!\n");
  }
  
  return 0;
}