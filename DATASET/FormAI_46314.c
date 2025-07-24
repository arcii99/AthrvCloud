//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>

int main() {
  float income, expenses, savings, net_worth;
  
  printf("Enter your income: $");
  scanf("%f", &income);

  printf("Enter your monthly expenses: $");
  scanf("%f", &expenses);

  savings = income - expenses;
  net_worth = savings * 12; // calculating annual net worth

  printf("\nYour monthly savings: $%.2f\n", savings);
  printf("Your annual net worth: $%.2f\n", net_worth);
  
  // checking if net worth is positive, negative, or zero
  if(net_worth < 0) {
    printf("Your net worth is negative. You should consider reviewing and reducing your expenses.\n");
  } else if(net_worth > 0) {
    printf("Your net worth is positive. Congratulations on your financial stability!\n");
  } else {
    printf("Your net worth is zero. You should consider increasing your income or reducing your expenses.\n");
  }

  return 0;
}