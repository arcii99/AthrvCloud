//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
// Ada Lovelace Personal Finance Planner

#include <stdio.h>

int main() {
  char name[20];
  int age;
  float salary, expense, savings;

  printf("Welcome to the Personal Finance Planner, created with love by Ada Lovelace.\n");
  printf("Please enter your name: ");
  scanf("%s", &name);

  printf("Hi, %s! Please enter your age: ", name);
  scanf("%d", &age);

  printf("Thank you! Now please enter your monthly salary: $");
  scanf("%f", &salary);

  printf("Great! And what are your monthly expenses? $");
  scanf("%f", &expense);

  savings = salary - expense;

  printf("\nBased on the information provided, here is your monthly budget:\n");
  printf("Monthly salary: $%.2f\n", salary);
  printf("Monthly expenses: $%.2f\n", expense);
  printf("Savings: $%.2f\n", savings);

  if (savings < 0) {
    printf("\nUh-oh! You are spending more than you make. It may be time to make some adjustments.\n");
  } else if (savings == 0) { 
    printf("\nLooks like you are breaking even. Keep up the good work!\n");
  } else {
    printf("\nGreat job! You are saving $%.2f each month. Keep it up!\n", savings);
  }

  printf("\nThank you for using the Personal Finance Planner. Have a great day!\n");

  return 0;
}