//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
#include <stdio.h>

int main() {
   float income, rent, utilities, groceries, transportation, entertainment, savings;
   
   printf("Welcome to the Personal Finance Planner!\n\n");
   
   //Ask for user input
   printf("What is your monthly income? ");
   scanf("%f", &income);
   
   printf("What is your monthly rent or mortgage payment? ");
   scanf("%f", &rent);
   
   printf("What do you typically spend on utilities each month? ");
   scanf("%f", &utilities);
   
   printf("What do you typically spend on groceries each month? ");
   scanf("%f", &groceries);
   
   printf("What do you typically spend on transportation each month? ");
   scanf("%f", &transportation);
   
   printf("What do you typically spend on entertainment each month? ");
   scanf("%f", &entertainment);
   
   printf("What percentage of your monthly income would you like to save? ");
   scanf("%f", &savings);
   
   //Calculate the user's expenses
   float total_expenses = rent + utilities + groceries + transportation + entertainment;
   
   //Calculate the user's monthly savings
   float monthly_savings = income * (savings/100);
   
   //Calculate the user's remaining budget after expenses and savings
   float remaining_budget = income - total_expenses - monthly_savings;
   
   //Print the results
   printf("\n\nYour total monthly expenses are: $%.2f\n", total_expenses);
   printf("You are saving: $%.2f\n", monthly_savings);
   printf("You have $%.2f remaining in your budget for the month.\n", remaining_budget);
   
   return 0;
}