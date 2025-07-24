//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>

int main(void) {
  
  // Welcome message
  printf("Welcome to the Personal Finance Planner! Let's start planning your finances.\n");

  // Declare variables
  float salary, expenses, savings;
  
  // Get input from user
  printf("Enter your monthly salary: $");
  scanf("%f", &salary);
  printf("Enter your monthly expenses: $");
  scanf("%f", &expenses);
  
  // Calculate savings
  savings = salary - expenses;
  
  // Display results
  printf("\nGreat! Based on your input, your monthly savings is $%.2f.\n\n", savings);

  // Check if user is on track for their financial goal
  if (savings >= 1000) {
    printf("Awesome job! You're on track to meet your financial goals.\n");
  } else {
    printf("Oops! It seems like you'll need to cut back on some of your expenses to meet your financial goals.\n");
  }

  // Thank user for using the program
  printf("\nThank you for using the Personal Finance Planner! Happy budgeting!");
  
  return 0;
}