//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include <stdio.h>

int main() {
   float income, expenses, savings;
   
   printf("Enter your monthly income: $");
   scanf("%f", &income);

   printf("Enter your monthly expenses: $");
   scanf("%f", &expenses);

   savings = income - expenses;
   
   printf("Your monthly income is $%.2f\n", income);
   printf("Your monthly expenses are $%.2f\n", expenses);
   printf("Your monthly savings are $%.2f\n", savings);

   if (savings < 0) {
      printf("You are spending more than you make. Consider cutting back on expenses.\n");
   } else if (savings < (income * 0.1)) {
      printf("You are saving less than 10%% of your income. Consider increasing your savings.\n");
   } else if (savings < (income * 0.2)) {
      printf("You are saving between 10%% and 20%% of your income. Good job!\n");
   } else {
      printf("You are saving more than 20%% of your income. Amazing job!\n");
   }
   
   return 0;
}