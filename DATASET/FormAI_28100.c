//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
struct expense {
    char category[50];
    float amount;
};
int main()
{
  int n, i;
  float total = 0;
  printf("Enter the number of expenses: ");
  scanf("%d", &n);
  struct expense expenses[n];
  for (i = 0; i < n; i++)
  {
    printf("\nEnter details for expense #%d:\n", i+1);
    printf("Category: ");
    scanf("%s", expenses[i].category);
    printf("Amount: ");
    scanf("%f", &expenses[i].amount);
    total += expenses[i].amount;
  }
  printf("\n*******************************\n");
  printf("Expense Tracker\n");
  printf("*******************************\n");
  printf("%-20s %10s \n", "Category", "Amount");
  for (i = 0; i < n; i++)
  {
    printf("%-20s %10.2f \n", expenses[i].category, expenses[i].amount);
  }
  printf("*******************************\n");
  printf("%-20s %10.2f \n", "Total", total);
  printf("*******************************\n");
  return 0;
}