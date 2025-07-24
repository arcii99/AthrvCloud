//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>

int main() {
  float monthlyIncome, monthlyExpenses, savingsGoal, currentSavings = 0;
  int numberOfMonths = 0;

  printf("Enter your monthly income: $");
  scanf("%f", &monthlyIncome);

  printf("Enter your monthly expenses: $");
  scanf("%f", &monthlyExpenses);

  printf("Enter your savings goal: $");
  scanf("%f", &savingsGoal);

  while(currentSavings < savingsGoal) {
    currentSavings += (monthlyIncome - monthlyExpenses);
    numberOfMonths++;
    printf("After month #%d, your current savings is: $%f\n", numberOfMonths, currentSavings);
  }

  printf("Congratulations! You will reach your savings goal of $%f in %d months!\n", savingsGoal, numberOfMonths);

  return 0;
}