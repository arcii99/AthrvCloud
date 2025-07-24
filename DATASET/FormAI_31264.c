//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>

struct Expense {
   char name[50];
   float cost;
};

float calculate_total_expenses(struct Expense expenses[], int num_expenses) {
   float total_cost = 0.0;
   for(int i=0; i<num_expenses; i++) {
      total_cost += expenses[i].cost;
   }
   return total_cost;
}

int main() {
   int num_expenses;
   printf("How many expenses do you have? ");
   scanf("%d", &num_expenses);

   struct Expense expenses[num_expenses];
   for(int i=0; i<num_expenses; i++) {
      printf("Enter the name of expense #%d: ", i+1);
      scanf("%s", expenses[i].name);
      printf("Enter the cost of expense #%d: ", i+1);
      scanf("%f", &expenses[i].cost);
   }

   float total_expenses = calculate_total_expenses(expenses, num_expenses);

   printf("\n\nEXPENSES\n");
   for(int i=0; i<num_expenses; i++) {
      printf("%s: $%.2f\n", expenses[i].name, expenses[i].cost);
   }
   printf("Total: $%.2f\n", total_expenses);

   return 0;
}