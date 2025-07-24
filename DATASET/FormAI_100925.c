//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>

int main() {
  float income, expenses, savings;

  printf("What is your monthly income? ");
  scanf("%f", &income);

  printf("What are your monthly expenses? ");
  scanf("%f", &expenses);

  savings = income - expenses;

  if (savings < 0) {
    printf("You are spending more than you make. Consider cutting expenses or finding ways to increase your income.");
  } else if (savings == 0) {
    printf("You are breaking even. Make sure to track your expenses and adjust as needed.");
  } else {
    printf("You have a monthly savings of $%.2f\n", savings);
  }

  printf("Do you have any debt? (y/n) ");
  char response = getchar();

  if (response == 'y') {
    float debt, interest;
    printf("What is your total debt amount? ");
    scanf("%f", &debt);

    printf("What is the interest rate on your debt? ");
    scanf("%f", &interest);

    float monthly_payment = debt * (interest / 100) / 12;
    printf("To pay off your debt in one year, you would need to make a monthly payment of $%.2f\n", monthly_payment);
  }

  return 0;
}