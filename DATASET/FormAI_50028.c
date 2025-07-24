//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  float income, rent, food, transportation, miscellaneous, savings;
  
  printf("Welcome to the Personal Finance Planner!\n\n");
  
  // prompt the user for their income and expenses
  
  printf("Please enter your monthly income: ");
  scanf("%f", &income);
  
  printf("\nPlease enter your monthly rent: ");
  scanf("%f", &rent);
  
  printf("\nPlease enter your monthly food expenses: ");
  scanf("%f", &food);
  
  printf("\nPlease enter your monthly transportation expenses: ");
  scanf("%f", &transportation);
  
  printf("\nPlease enter your monthly miscellaneous expenses: ");
  scanf("%f", &miscellaneous);
  
  // calculate and display the user's monthly savings
  
  savings = income - (rent + food + transportation + miscellaneous);
  
  printf("\n\nBased on your input, your monthly savings will be: $%.2f\n\n", savings);
  
  // offer advice based on the user's financial situation
  
  if (savings < 0) {
    printf("It looks like you're spending more than you're making. Consider reviewing your expenses and finding areas where you can cut back.\n\n");
  } else if (savings < 500) {
    printf("You're doing okay, but there's room for improvement. Try to save a little more each month if you can!\n\n");
  } else if (savings < 1000) {
    printf("Great job! You're on the right track. Keep up the good work!\n\n");
  } else {
    printf("Wow, you're doing fantastic! Make sure you keep up with this budget so you can continue to save and invest in your future.\n\n");
  }
  
  return 0;
}