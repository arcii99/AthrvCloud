//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   float salary;
   float expenses;
   float savings;
} Budget;

void getBudget(Budget* b) {
   printf("Enter your salary: ");
   scanf("%f", &b->salary);
   printf("Enter your total monthly expenses: ");
   scanf("%f", &b->expenses);
   b->savings = b->salary - b->expenses;
}

void printBudget(Budget b) {
   printf("Salary: $%.2f\n", b.salary);
   printf("Total monthly expenses: $%.2f\n", b.expenses);
   printf("Total savings: $%.2f\n", b.savings);
}

int main() {
   Budget myBudget;
   getBudget(&myBudget);
   printBudget(myBudget);
   
   return 0;
}