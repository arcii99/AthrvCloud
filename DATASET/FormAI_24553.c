//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>

int main() {
  float income;
  float expenses;
  float saving;
  float investment;

  printf("Enter your monthly income: ");
  scanf("%f", &income);

  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);

  saving = income - expenses;
  printf("Your monthly savings: $%.2f\n", saving);

  printf("How much do you want to invest per month? ");
  scanf("%f", &investment);

  float interest_rate = 0.05; // 5% interest rate per year
  float years = 10; // investment period, 10 years
  float total_interest = 0;
  float total_saving = saving * years * 12;

  for (int i = 1; i <= years; i++) {
    total_interest += (total_saving + investment) * interest_rate;
    total_saving += investment + total_interest;
  }

  printf("After %d years, your total savings is: $%.2f\n", (int)years, total_saving);
  printf("You earned a total interest of: $%.2f\n", total_interest);

  return 0;
}