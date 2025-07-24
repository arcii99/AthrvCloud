//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
   float income, rent, utilities, groceries, transportation, entertainment, savings, expenses;
   
   printf("****** Personal Finance Planner ******\n\n");

   /* Get user input income and expenses */
   printf("Please enter your monthly income: $");
   scanf("%f", &income);
   printf("Please enter your monthly rent/mortgage payment: $");
   scanf("%f", &rent);
   printf("Please enter your monthly utility bill payment: $");
   scanf("%f", &utilities);
   printf("Please enter your monthly grocery bill payment: $");
   scanf("%f", &groceries);
   printf("Please enter your monthly transportation bill payment: $");
   scanf("%f", &transportation);
   printf("Please enter your monthly entertainment bill payment: $");
   scanf("%f", &entertainment);
   printf("Please enter your monthly savings amount: $");
   scanf("%f", &savings);

   /* Calculate total expenses*/
   expenses = rent + utilities + groceries + transportation + entertainment + savings;

   /* Determine if user is living within their means */
   if (income > expenses) {
       printf("\nYou are living within your means! Congratulations!\n");
   } else if (income == expenses) {
       printf("\nYou are breaking even this month.\n");
   } else {
       printf("\nWarning, you are spending more than you are making. Consider cutting back on expenses.\n");
   }

   /* Calculate and display breakdown of expenses */
   printf("\nYour monthly expenses are as follows:\nRent/Mortgage: $%.2f\nUtilities: $%.2f\nGroceries: $%.2f\nTransportation: $%.2f\nEntertainment: $%.2f\nSavings: $%.2f\n", rent, utilities, groceries, transportation, entertainment, savings);

   return 0;
}