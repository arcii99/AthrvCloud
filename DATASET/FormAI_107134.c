//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>

int main() {
  int salary;
  int savings = 0;
  int expenses;
  int month = 1;

  printf("Hello and welcome to your personal finance planner!\n\n");

  printf("Please enter your monthly salary: ");
  scanf("%d", &salary);

  while (month <= 12) {
    printf("\nMonth %d\n", month);
    printf("----------------------------\n");
    printf("Monthly salary: $%d\n", salary);

    printf("Please enter your monthly expenses: ");
    scanf("%d", &expenses);

    savings += salary - expenses;
    printf("Total savings: $%d\n", savings);

    month++;
  }

  printf("\nThank you for using your personal finance planner!\n");

  return 0;
}