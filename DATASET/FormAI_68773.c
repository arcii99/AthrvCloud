//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>

int main() {
  float income, rent, groceries, transportation, entertainment, savings;
  
  printf("Enter your monthly income: ");
  scanf("%f", &income);
  
  printf("Enter your monthly rent or mortgage payment: ");
  scanf("%f", &rent);
  
  printf("Enter your monthly grocery expenses: ");
  scanf("%f", &groceries);
  
  printf("Enter your monthly transportation expenses: ");
  scanf("%f", &transportation);
  
  printf("Enter your monthly entertainment expenses: ");
  scanf("%f", &entertainment);
  
  savings = income - (rent + groceries + transportation + entertainment);
  
  printf("Your monthly savings: $%.2f", savings);
  
  return 0;
}