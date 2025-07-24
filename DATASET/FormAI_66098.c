//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

int main() {
  char date[20];
  int day,month,year;

  printf("Enter a date in natural language (e.g. October 13, 2021): ");
  fgets(date,20,stdin);
  
  sscanf(date,"%d/%d/%d",&day,&month,&year);
  
  printf("\nYour date in numerical format is: %02d/%02d/%04d",month,day,year);

  return 0;
}