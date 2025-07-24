//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
#include <stdio.h>

int main() {
   float income, expenses, savings;

   printf("Welcome to Personal Finance Planner!\n");

   printf("Please enter your monthly income: $");
   scanf("%f", &income);

   printf("Please enter your monthly expenses: $");
   scanf("%f", &expenses);

   savings = income - expenses;

   if (savings > 0) {
      printf("\nGreat job! You have saved $%.2f this month.\n", savings);
   } else if (savings < 0) {
      printf("\nUh oh! You have overspent by $%.2f this month.\n", savings * -1);
   } else {
      printf("\nYou have broken even this month.\n");
   }

   return 0;
}