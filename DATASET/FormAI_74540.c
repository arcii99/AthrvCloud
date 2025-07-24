//FormAI DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

int main(){
  int expenses[7];
  int total=0;
  int i;
  for(i=0;i<7;i++){
    printf("Enter expense for day %d: ",i+1);
    scanf("%d",&expenses[i]);
    total+=expenses[i];
  }
  printf("\nExpense Tracker\n");
  printf("Day\tAmount\n");
  for(i=0;i<7;i++){
    printf("%d\t%d\n",i+1,expenses[i]);
  }
  printf("Total Expense: %d\n",total);

  return 0;
}