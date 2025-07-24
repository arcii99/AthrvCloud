//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>

int main() {
   float income, expenses, savings;
   
   printf("Enter your monthly income: $");
   scanf("%f", &income);
   
   printf("Enter your monthly expenses: $");
   scanf("%f", &expenses);
   
   savings = income - expenses;
   
   if(savings >= 0) {
      printf("You have a surplus of $%.2f each month.\n", savings);
   } else {
      printf("You have a deficit of $%.2f each month.\n", -savings);
   }
   
   printf("Your annual surplus/deficit is $%.2f.\n", savings * 12);
   
   return 0;
}