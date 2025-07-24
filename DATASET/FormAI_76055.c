//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>

int main() {
   float salary;       // Annual salary
   int months;         // Number of months in planning period
   float expenses;     // Total expenses over planning period
   float savingsRate;  // Monthly savings rate
   float currentSavings;  // Current savings at end of each month
   float r = 0.002;    // Monthly interest rate
   int i;              // Loop variable
   
   // Get inputs
   printf("Enter your annual salary: ");
   scanf("%f", &salary);
   printf("Enter the number of months in your planning period: ");
   scanf("%d", &months);
   printf("Enter your total expenses over the entire planning period: ");
   scanf("%f", &expenses);
   
   // Calculate monthly savings rate
   savingsRate = (salary / 12 * 0.2);
   printf("\nYour savings rate is: %f\n", savingsRate);  
   
   // Initialize current savings to 0
   currentSavings = 0;
   
   // Loop through each month of planning period
   for (i = 1; i <= months; i++) {
      // Add contributions from salary and interest to current savings
      currentSavings += (savingsRate / r) * (1 - (1 / pow((1 + r), i)));
      
      // Subtract expenses from current savings
      currentSavings -= (expenses / months);
      
      // Display current savings at the end of each month
      printf("End of month %d: $%.2f\n", i, currentSavings);
   }

   return 0;
}