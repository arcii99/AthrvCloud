//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>

// main function
int main() {
  float salary, expenses, savings;
 
  printf("Welcome to Personal Finance Planner!\n");
  printf("Please enter your monthly salary: ");
  scanf("%f", &salary);
  
  printf("\nPlease enter your monthly expenses: ");
  scanf("%f", &expenses);
 
  savings = salary - expenses;
 
  if(savings > 0) {
    printf("\nGreat job! You saved $%.2f this month!\n", savings);
  } else if(savings < 0) {
    printf("\nUh oh! You spent more than you earned!\n");
    printf("You are $%.2f in debt this month.\n", savings);
  } else {
    printf("\nYou spent exactly what you earned this month.\n");
  }
 
  return 0;
}