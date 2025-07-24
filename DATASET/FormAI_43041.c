//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>

int main() {
  double salary, rent, food, transportation, entertainment, savings;
  
  // Input monthly expenses
  printf("Enter your monthly salary: ");
  scanf("%lf", &salary);
  
  printf("Enter your monthly rent: ");
  scanf("%lf", &rent);
  
  printf("Enter your monthly food expenses: ");
  scanf("%lf", &food);
  
  printf("Enter your montly transportation expenses: ");
  scanf("%lf", &transportation);
  
  printf("Enter your monthly entertainment expenses: ");
  scanf("%lf", &entertainment);
  
  // Calculate savings
  savings = salary - rent - food - transportation - entertainment;
  
  // Output savings and financial advice
  printf("\n\n\n");
  printf("====PERSONAL FINANCE PLANNER====\n\n\n");
  printf("Your monthly savings is: $%.2lf\n", savings);
  
  if (savings < 0) {
    printf("You are spending more than you make! Consider reducing your expenses.\n");
  } else if (savings < (0.2 * salary)) {
    printf("You have a small margin of savings. Consider cutting back on entertainment expenses.\n");
  } else if (savings < (0.4 * salary)) {
    printf("You have a good margin of savings. Keep up the good work!\n");
  } else {
    printf("You have an excellent margin of savings! Consider investing your money to make even more.\n");
  }
  
  return 0;
}