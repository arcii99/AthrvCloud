//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>

struct expense {
   char name[50];
   float amount;
};

int main() {
   int num_expenses;
   float total_expenses = 0.0;

   printf("Welcome to the Personal Finance Planner!\n\n");

   printf("How many expenses do you have this month? ");
   scanf("%d", &num_expenses);

   // Allocate space for the expenses
   struct expense* expenses = (struct expense*) malloc(num_expenses * sizeof(struct expense));

   // Get the expense details from the user
   for (int i = 0; i < num_expenses; i++) {
      printf("\nExpense #%d\n", i+1);
      printf("Name: ");
      scanf("%s", expenses[i].name);
      printf("Amount: $");
      scanf("%f", &expenses[i].amount);

      total_expenses += expenses[i].amount;
   }

   // Print out the total expenses
   printf("\nTotal Expenses: $%.2f\n\n", total_expenses);

   // Free the memory used for the expenses
   free(expenses);

   return 0;
}