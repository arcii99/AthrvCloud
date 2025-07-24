//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>

int main() {
  float income, expenses;
  printf("Welcome to the Personal Finance Planner!\n\n");
  printf("Please input your monthly income: $");
  scanf("%f", &income);
  printf("\nPlease input your monthly expenses: $");
  scanf("%f", &expenses);
  float savings = income - expenses;
  printf("\nYour monthly savings is: $%.2f\n\n", savings);
  if (savings > 0) {
    printf("Congratulations! You are saving money each month!\n");
    printf("Your savings rate is: %.2f%%\n", (savings/income)*100);
  } else if (savings == 0) {
    printf("You are breaking even each month.\n");
  } else {
    printf("Uh oh! You are spending more than you make each month.\n");
    printf("You are overspending by: $%.2f\n", savings*-1);
    printf("Your overspending rate is: %.2f%%\n", (savings/income)*100*-1);
  }
  printf("\nThank you for using the Personal Fiance Planner!\n");
  return 0;
}