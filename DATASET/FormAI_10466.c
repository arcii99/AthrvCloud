//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>

int main() {
   float salary, expenses, savings;
   
   printf("Welcome to the Personal Finance Planner!\n");
   printf("Enter your monthly salary: ");
   scanf("%f", &salary);
   printf("Enter your monthly expenses: ");
   scanf("%f", &expenses);
   
   if (salary <= expenses) {
      printf("Uh oh, you are living paycheck to paycheck!\n");
   }
   
   savings = salary - expenses;
   
   printf("Congratulations! You have $%.2f left over every month.\n", savings);
   printf("What would you like to do with your savings?\n");
   printf("a. Invest in the stock market\n");
   printf("b. Put it in a savings account\n");
   printf("c. Spend it on a luxurious vacation\n");
   
   char choice;
   scanf(" %c", &choice);
   
   switch(choice) {
      case 'a':
         printf("Excellent choice! Let's hope the market is in your favor.\n");
         break;
      case 'b':
         printf("Boring, but safe.\n");
         break;
      case 'c':
         printf("Live a little!\n");
         break;
      default:
         printf("Invalid choice. Your savings will just sit there and collect dust.\n");
         break;
   }
   
   printf("Thanks for using Personal Finance Planner!\n");
   
   return 0;
}