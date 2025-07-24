//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>

int main() {
   float saving, salary, expenses;

   printf("Enter your monthly salary: ");
   scanf("%f", &salary);

   printf("Enter your monthly expenses: ");
   scanf("%f", &expenses);

   saving = salary - expenses;

   if (saving >= 0) {
       printf("Congratulations! You have a monthly saving of $%.2f.\n", saving);
   } else {
       printf("Warning! You are spending more than you earn. Try to reduce your expenses or find ways to increase your income.\n");
   }

   // Calculate yearly savings
   float yearly_savings = saving * 12;

   printf("Your yearly savings are $%.2f.\n", yearly_savings);

   // Calculate monthly savings as a percentage of income
   float percent_savings = (saving / salary) * 100;

   printf("Your monthly savings are %.2f%% of your income.\n", percent_savings);

   // Calculate investment options
   float investment_options[] = {0.10, 0.25, 0.50};
   float investment_returns[3];

   printf("You can consider investing your savings in the following options:\n");

   for (int i = 0; i < 3; i++) {
       investment_returns[i] = saving * 12 * investment_options[i];
       printf("Option %d: $%.2f return on investment per year.\n", i+1, investment_returns[i]);
   }

   return 0;
}