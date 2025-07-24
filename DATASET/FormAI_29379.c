//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Touring
#include <stdio.h>

int main() {
   float currentSavings, goalSavings, monthlyIncome, monthlyExpenses;
   
   // Input current savings, goal savings, monthly income, and monthly expenses
   printf("Enter your current savings: ");
   scanf("%f", &currentSavings);
   
   printf("Enter your goal savings: ");
   scanf("%f", &goalSavings);
   
   printf("Enter your monthly income: ");
   scanf("%f", &monthlyIncome);
   
   printf("Enter your monthly expenses: ");
   scanf("%f", &monthlyExpenses);
   
   // Calculate how many months until goal savings is reached
   float savingsPerMonth = monthlyIncome - monthlyExpenses;
   float monthsUntilGoal = (goalSavings - currentSavings) / savingsPerMonth;
   
   // Display the result
   printf("You need to save for %.0f months to reach your goal of $%.2f.\n", monthsUntilGoal, goalSavings);
   
   return 0;
}