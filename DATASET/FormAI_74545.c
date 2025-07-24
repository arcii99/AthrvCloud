//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
   printf("Welcome to the Surreal Personal Finance Planner\n");
   printf("--------------------------------------------\n");
    
   int income, expenses;
 
   printf("Enter your monthly income: ");
   scanf("%d", &income);
 
   printf("Enter your monthly expenses: ");
   scanf("%d", &expenses);
 
   int netIncome = income - expenses;
   float savingAmount;
 
   if(netIncome > 0)
   {
      savingAmount = netIncome * 0.20;
      printf("Congratulations, you have a positive net income!\n");
      printf("You should consider saving at least %.2f for unexpected expenses.\n", savingAmount);
 
      if(netIncome > 1000)
      {
          printf("You can also consider investing in some surreal financial instruments.\n");
      }
      else
      {
          printf("Your monthly income is not enough to consider investing.\n");
      }
   }
   else if(netIncome == 0)
   {
      printf("You are living within your means, but still be cautious.\n");
   }
   else
   {
      printf("You have a negative net income. Consider re-evaluating your expenses.\n");
   }
 
   return 0;
}