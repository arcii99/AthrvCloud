//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>

int main() {
   float income, expenses, savings;
   float rent, bills, food, transportation, other;

   printf("Enter your monthly income:\n");
   scanf("%f", &income);
   printf("Enter your monthly expenses:\n");
   scanf("%f", &expenses);

   // Calculate savings
   savings = income - expenses;

   printf("\nYour monthly savings: %.2f\n", savings);

   // Break down expenses
   printf("\nBreakdown of expenses:\n");

   printf("Rent/mortgage:\n");
   scanf("%f", &rent);
   printf("Bills/utilities:\n");
   scanf("%f", &bills);
   printf("Food:\n");
   scanf("%f", &food);
   printf("Transportation:\n");
   scanf("%f", &transportation);
   printf("Other:\n");
   scanf("%f", &other);

   // Sum up total expenses
   expenses = rent + bills + food + transportation + other;

   printf("\nTotal monthly expenses: %.2f\n", expenses);
   
   return 0;
}