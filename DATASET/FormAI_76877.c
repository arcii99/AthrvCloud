//FormAI DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct expense {
   char category[20];
   float amount;
   char date[10];
};

int main() {
   int numExpenses;
   printf("How many expenses do you want to track? ");
   scanf("%d", &numExpenses);

   struct expense *expenses = (struct expense *)malloc(numExpenses * sizeof(struct expense));
   if (expenses == NULL) {
      printf("Memory allocation error!");
      return 1;
   }

   for (int i = 0; i < numExpenses; i++) {
      printf("\nEnter expense category: ");
      scanf("%s", &expenses[i].category);
      printf("Enter expense amount: $");
      scanf("%f", &expenses[i].amount);
      printf("Enter expense date (MM/DD/YYYY): ");
      scanf("%s", &expenses[i].date);
   }

   printf("\nExpense Report:\n");
   printf("-------------------------------------------------------\n");
   printf("Category\t\tAmount\t\tDate\n");
   printf("-------------------------------------------------------\n");
   for (int i = 0; i < numExpenses; i++) {
      printf("%-20s\t$%-10.2f\t%s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
   }
   printf("-------------------------------------------------------\n");

   free(expenses);
   return 0;
}