//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int income, expenses, savings;
  printf("Welcome to the Personal Finance Planner!\n\n");
  
  // Input income
  printf("Please enter your monthly income: ");
  scanf("%d", &income);
  
  // Input expenses
  printf("Please enter your monthly expenses: ");
  scanf("%d", &expenses);
  
  // Calculate savings
  savings = income - expenses;
  
  // Output results
  printf("\nYour monthly income is: $%d\n", income);
  printf("Your monthly expenses are: $%d\n", expenses);
  printf("Your monthly savings are: $%d\n", savings);
  
  // Check if savings are positive
  if(savings > 0)
  {
    printf("\nCongratulations! You are saving money every month!\n");
  }
  else if(savings < 0)
  {
    printf("\nUh-oh, it looks like you are spending more than you are earning.\n");
  }
  else
  {
    printf("\nYou are breaking even every month. It's time to start saving more!\n");
  }
  
  return 0;
}