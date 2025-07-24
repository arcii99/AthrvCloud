//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct expense {
  char category[20];
  float amount;
};

int main() {
  int n, total = 0;
  printf("How many expenses would you like to enter? ");
  scanf("%d", &n);
  struct expense expenses[n];

  for (int i = 0; i < n; i++) {
    printf("Enter Expense #%d Category: ", i+1);
    scanf("%s", &expenses[i].category);
    printf("Enter Expense #%d Amount: ", i+1);
    scanf("%f", &expenses[i].amount);
    total += expenses[i].amount;
  }
  
  printf("\nExpense Report\n");
  printf("==============\n");
  for (int i = 0; i < n; i++) {
    printf("%s: %.2f\n", expenses[i].category, expenses[i].amount);
  }
  printf("Total: %.2f", total);

  return 0;
}