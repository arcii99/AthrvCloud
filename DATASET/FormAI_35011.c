//FormAI DATASET v1.0 Category: Digital Diary ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int date, month, year, hour, minute, choice;
  char entry[1000];
  
  printf("Welcome to your Digital Diary!\n");
  
  printf("Enter today's date in DD format: ");
  scanf("%d", &date);
  
  printf("Enter today's month in MM format: ");
  scanf("%d", &month);
  
  printf("Enter today's year in YYYY format: ");
  scanf("%d", &year);
  
  printf("Enter the current hour in HH format (24-hour clock): ");
  scanf("%d", &hour);
  
  printf("Enter the current minute in MM format: ");
  scanf("%d", &minute);
  
  printf("\nCurrent date and time: %02d/%02d/%04d %02d:%02d\n", date, month, year, hour, minute);
  
  printf("\nDo you want to write a new entry?\n1. Yes\t2. No\n");
  scanf("%d", &choice);
  
  if(choice == 1)
  {
    printf("\nEnter your entry:\n");
    scanf(" %[^\n]s", entry);
    
    printf("\nEntry added successfully!\n");
  }
  else if(choice == 2)
  {
    printf("\nExiting program. Goodbye!\n");
    exit(0);
  }
  
  return 0;
}