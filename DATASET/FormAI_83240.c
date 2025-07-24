//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>

int main() {
   float salary, expenses, savings;
   char choice;

   printf("Enter your monthly salary: ");
   scanf("%f", &salary);

   printf("Enter your monthly expenses: ");
   scanf("%f", &expenses);

   savings = salary - expenses;
   
   printf("\nYour monthly savings: %.2f\n", savings);

   printf("\nDo you want to create a yearly budget? [Y/N]: ");
   scanf(" %c", &choice);

   if(choice == 'Y' || choice == 'y'){
      float yearly_budget = savings * 12;

      printf("\nYour yearly budget: %.2f\n", yearly_budget);
   }

   return 0;
}