//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
#include <stdio.h>

int main() {
   int income, expenses, saving;

   printf("Enter your monthly income: ");
   scanf("%d", &income);

   printf("Enter your monthly expenses: ");
   scanf("%d", &expenses);

   saving = income - expenses;

   if(saving > 0) {
      printf("You have saved %d dollars this month.\n", saving);
   } else if(saving < 0) {
      printf("You have overspent by %d dollars this month.\n", -saving);
   } else {
      printf("You have neither saved nor overspent this month.\n");
   }

   return 0;
}