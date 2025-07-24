//FormAI DATASET v1.0 Category: Expense Tracker ; Style: happy
#include<stdio.h>
#include<stdlib.h>

int main() {
  int expenses[31];
  int total = 0;

  printf("Welcome to your Expense Tracker App!\n\n");
  
  for(int i=1; i<=31; i++) {
     printf("Enter expense for Day %d: ", i);
     scanf("%d", &expenses[i-1]);
     total += expenses[i-1];
  }

  printf("\n\nYour Expense Tracker for the month of June is as follows:\n\n");

  for(int i=0; i<31; i++) {
     printf("Day %d: $%d\n", i+1, expenses[i]);
  }

  printf("Total Expenses for June: $%d\n", total);

  if(total < 1000) {
     printf("Congratulations! You have spent less than $1000 this month!\n");
  } else if(total < 5000) {
     printf("You have spent over $1000, but less than $5000 this month.\n");
  } else if(total < 10000) {
     printf("You have spent over $5000, but less than $10000 this month.\n");
  } else {
     printf("You have spent over $10000 this month! Better be careful.\n");
  }

  return 0;
}