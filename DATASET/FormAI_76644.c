//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct expense {
  float amount;
  char description[50];
  char date[15];
};

int main() {
  int num_expenses, i;
  
  printf("Enter the number of expenses you want to track: ");
  scanf("%d", &num_expenses);
  
  struct expense expenses[num_expenses];
  
  for(i=0; i<num_expenses; i++) {
    printf("\nEnter expense #%d details:\n", i+1);
    
    printf("Amount: ");
    scanf("%f", &expenses[i].amount);
    
    printf("Description: ");
    scanf("%s", expenses[i].description);
    
    printf("Date (dd/mm/yyyy): ");
    scanf("%s", expenses[i].date);
  }
  
  printf("\n\nExpense Summary\n");
  
  printf("%-15s%-25s%s\n", "Amount", "Description", "Date");
  for(i=0; i<num_expenses; i++) {
    printf("%-15.2f%-25s%s\n", expenses[i].amount, expenses[i].description, expenses[i].date);
  }
  
  return 0;
}