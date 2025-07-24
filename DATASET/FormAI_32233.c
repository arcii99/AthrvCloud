//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
  float income, expenses, savings;

  printf("Welcome to the Personal Finance Planner!\n");
  printf("----------------------------------------\n");

  printf("Enter your monthly income: ");
  scanf("%f", &income);

  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);

  //Calculate savings
  savings = income - expenses;

  printf("\nYour monthly savings: $%.2f\n", savings);

  //Monthly vs. yearly savings
  float yearlySavings = savings * 12;

  printf("Yearly savings: $%.2f\n", yearlySavings);

  if(yearlySavings < 1000){
    printf("You need to work on saving more money!\n");
  } else if (yearlySavings >= 1000 && yearlySavings < 10000) {
    printf("Great job! You are on the right track!\n");
  } else {
    printf("Wow! You are a financial rockstar! Keep it up!\n");
  }

  //Savings percentage
  float percentSaved = (savings / income) * 100;

  printf("You saved %.2f%% of your income this month.\n", percentSaved);

  //Emergency fund calculation
  float emergencyFund = expenses * 6;
  printf("Your recommended emergency fund should be: $%.2f\n", emergencyFund);

  return 0;
}