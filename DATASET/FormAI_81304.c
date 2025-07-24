//FormAI DATASET v1.0 Category: Expense Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

struct expense {
  char category[20];
  float amount;
};

typedef struct expense Expense; // define new type

int main() {
  printf("Welcome to the Mind-Bending Expense Tracker!\n");
  
  int num_expenses;
  printf("How many expenses would you like to enter? ");
  scanf("%d", &num_expenses);
  getchar(); // consume newline
  
  Expense* expenses = (Expense*) malloc(num_expenses * sizeof(Expense));
  
  for(int i = 0; i < num_expenses; i++) {
    printf("\nExpense #%d:\n", i+1);
    printf("Enter the category: ");
    fgets(expenses[i].category, 20, stdin);
    printf("Enter the amount: ");
    scanf("%f", &expenses[i].amount);
    getchar(); // consume newline
  }

  printf("\n\nYour Expenses are:\n");
  printf("Category\t\tAmount\n");
  printf("--------------------------------------\n");
  
  float total_expenses = 0;
  for(int i = 0; i < num_expenses; i++) {
    printf("%s\t\t\t$%.2f\n", expenses[i].category, expenses[i].amount);
    total_expenses += expenses[i].amount;
  }

  printf("\nTotal Expenses: $%.2f", total_expenses);
  
  free(expenses);
  
  printf("\n\nThank you for using the Mind-Bending Expense Tracker!\n");
  
  return 0;
}