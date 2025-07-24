//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: scalable
#include <stdio.h>

int main() {
   float monthlyIncome, rent, utilities, groceries, transportation, phone, otherExpenses;
   
   printf("Please enter your monthly income: ");
   scanf("%f", &monthlyIncome);
   
   printf("Please enter your monthly rent/mortgage expense: ");
   scanf("%f", &rent);
   
   printf("Please enter your monthly utilities expense: ");
   scanf("%f", &utilities);
   
   printf("Please enter your monthly groceries expense: ");
   scanf("%f", &groceries);
   
   printf("Please enter your monthly transportation expense: ");
   scanf("%f", &transportation);
   
   printf("Please enter your monthly phone expense: ");
   scanf("%f", &phone);
   
   printf("Please enter any other monthly expenses: ");
   scanf("%f", &otherExpenses);
   
   float totalExpenses = rent + utilities + groceries + transportation + phone + otherExpenses;
   float savings = monthlyIncome - totalExpenses;
   float percentSavings = (savings / monthlyIncome) * 100;
   
   printf("\n\n########## PERSONAL FINANCE PLANNER ##########\n\n");
   
   printf("Your monthly income: $%.2f\n", monthlyIncome);
   printf("Your total monthly expenses: $%.2f\n", totalExpenses);
   printf("Your monthly savings: $%.2f\n", savings);
   printf("Your savings as a percentage of income: %.2f%%\n", percentSavings);
   
   if (savings >= 0) {
      printf("\nCongratulations! You have a positive monthly savings.\n");
   } else {
      printf("\nWarning! Your monthly expenses are higher than your income. You have a negative monthly savings.\n");
   }
   
   return 0;
}