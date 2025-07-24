//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
  float monthly_income, expenses, savings, taxes;
  
  printf("Welcome to the Personal Finance Planner!\n");
  printf("Please enter your monthly income: ");
  scanf("%f", &monthly_income);
  
  printf("Please enter your monthly expenses: ");
  scanf("%f", &expenses);
  
  printf("Please enter your tax rate (in decimal form): ");
  scanf("%f", &taxes);
  
  savings = (monthly_income - expenses) * (1 - taxes);
  
  printf("Based on the information you provided, your monthly savings is $%.2f\n", savings);
  
  if (savings < 0) {
    printf("Uh oh! It looks like you're spending more money than you're making. Consider revising your budget.\n");
  } else if (savings < 500) {
    printf("Your savings could be higher. Consider cutting back on unnecessary expenses.\n");
  } else {
    printf("Congratulations! Your savings are on track. Keep up the good work!\n");
  }
  
  return 0;
}