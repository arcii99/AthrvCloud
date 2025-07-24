//FormAI DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct expense {
   char category[20];
   float amount;
};

int main() {
   int num_expenses, total_expenses = 0;
   printf("Welcome to the Expense Tracker\n\n");

   printf("How many expenses would you like to add?\n");
   scanf("%d", &num_expenses);

   struct expense *expenses = (struct expense*) malloc(num_expenses * sizeof(struct expense));

   for(int i=0; i<num_expenses; i++) {
      printf("\nExpense #%d\nCategory: ", i+1);
      scanf("%s", expenses[i].category);

      printf("Amount: ");
      scanf("%f", &expenses[i].amount);

      total_expenses += expenses[i].amount;
   }

   printf("\n\n ---Expense Report---\n");
   printf("Total Expenses: $%.2f\n\n", total_expenses);

   for(int i=0; i<num_expenses; i++) {
      printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
   }

   free(expenses);
   expenses = NULL;
   
   return 0;
}