//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct expense {
  int id;
  char item[50];
  float cost;
}exp[100];

int addNewExpense(int n);
void printExpenses(int n);
int deleteExpense(int n);

int main() {
  int option, n=0;
  do {
    printf("\nSelect option:");
    printf("\n1. Add new expense");
    printf("\n2. Print all expenses");
    printf("\n3. Delete an expense");
    printf("\n4. Exit");

    scanf("%d", &option);

    switch(option) {
      case 1:
        n = addNewExpense(n);
        break;
      case 2:
        printExpenses(n);
        break;
      case 3:
        n = deleteExpense(n);
        break;
      case 4:
        printf("\nExiting expense tracker\n");
        break;
      default:
        printf("\nInvalid option, please try again.\n");
        break;
    }
  } while(option != 4);
  return 0;
}

int addNewExpense(int n) {
  printf("\nEnter expense ID: ");
  scanf("%d", &exp[n].id);

  printf("Enter item name: ");
  scanf("%s", exp[n].item);

  printf("Enter cost: ");
  scanf("%f", &exp[n].cost);

  n++;
  printf("\nExpense added successfully!\n");
  return n;
}

void printExpenses(int n) {
  if(n == 0) {
      printf("\nNo expenses added yet.\n");
      return;
  }
  printf("\nAll Expenses:\n");
  printf("ID\tItem\t\tCost\n");
  for(int i=0; i<n; i++) {
      printf("%d\t%s\t\t%.2f\n", exp[i].id, exp[i].item, exp[i].cost);
  }
}

int deleteExpense(int n) {
  if(n == 0) {
      printf("\nNo expenses added yet.\n");
      return n;
  }
  int id;
  int index = -1;
  printf("\nEnter ID of expense to delete: ");
  scanf("%d", &id);

  for(int i=0; i<n; i++) {
      if(exp[i].id == id) {
          index = i;
          break;
      }
  }

  if(index == -1) {
      printf("Expense not found for ID %d\n", id);
  } else {
      for(int i=index; i<n-1; i++) {
          exp[i] = exp[i+1];
      }
      n--;
      printf("Expense with ID %d deleted successfully!\n", id);
  }

  return n;
}