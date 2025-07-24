//FormAI DATASET v1.0 Category: Expense Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
  char category[20];
  double amount;
  char date[11];
}exp;

int main()
{
  char response;
  FILE *fp;

  printf("Welcome to your personal expense tracker.\n");

  do{
    printf("\nWould you like to (A)dd an expense or (V)iew expense by category? ");
    scanf(" %c", &response);

    if(response == 'A' || response == 'a'){
      fp = fopen("expenses.txt", "a");
      if(fp == NULL){
        printf("Error opening file.\n");
        exit(1);
      }
      printf("\nEnter the category: ");
      scanf("%s", exp.category);
      printf("Enter the amount: ");
      scanf("%lf", &exp.amount);
      printf("Enter the date (DD/MM/YYYY): ");
      scanf("%s", exp.date);
      fprintf(fp, "%s %.2lf %s\n", exp.category, exp.amount, exp.date);
      printf("Expense added successfully!\n");
      fclose(fp);
    }
    else if(response == 'V' || response == 'v'){
      double total = 0;
      char search[20];
      int flag = 0;
      printf("\nEnter the category to view: ");
      scanf("%s", search);
      fp = fopen("expenses.txt", "r");
      if(fp == NULL){
        printf("Error opening file.\n");
        exit(1);
      }
      printf("Expenses in %s category:\n", search);
      while(fscanf(fp, "%s %lf %s\n", exp.category, &exp.amount, exp.date)!= EOF){
        if(strcmp(search, exp.category) == 0){
          printf("%.2lf on %s\n", exp.amount, exp.date);
          total += exp.amount;
          flag = 1;
        }
      }
      if(flag == 0){
        printf("No expenses found in %s category.\n", search);
      }
      else{
        printf("Total expenses in %s category is %.2lf\n", search, total);
      }
      fclose(fp);
    }
    else{
      printf("Invalid response. Try again.\n");
    }
  }
  while(response != 'q' || response != 'Q');

  return 0;
}