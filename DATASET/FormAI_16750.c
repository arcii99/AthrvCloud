//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>

int main() {
   float budget;
   printf("Welcome to the expense tracker!\n");
   printf("Please input your monthly budget: ");
   scanf("%f", &budget);
   
   float expense = 0;
   char choice;
   do {
      printf("\n\nEnter the type of expense (e.g. food, transportation, rent): ");
      char type[50];
      scanf("%s", type);
      printf("Enter the amount spent: ");
      float amount;
      scanf("%f", &amount);
      expense += amount;
      printf("Do you have more expenses to log? (Y/N) ");
      scanf(" %c", &choice);
   } while(choice == 'Y' || choice == 'y');

   float remaining = budget - expense;
   printf("\n---------- EXPENSES FOR THE MONTH ----------\n\n");
   printf("Total budget: $%.2f\n", budget);
   printf("Total expenses: $%.2f\n", expense);
   printf("Remaining budget: $%.2f\n", remaining);

   if(remaining > 0){
      printf("\nYou saved $%.2f this month! Great job!", remaining);
   }
   else{
      printf("\nYou have overspent your budget by $%.2f! Please control your expenses.", -remaining);
   }

   return 0;
}