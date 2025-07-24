//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("***Welcome to the Time Travel Simulator***\n\n");

  printf("Enter a year between 2022 and 3022:\n");
  int year;
  scanf("%d",&year);
  
  if (year < 2022 || year > 3022) {
    printf("Sorry, time travel to this year is not possible. Try again!\n");
    exit(0);
  }
  
  printf("\nPreparing to Time Travel... Please wait...\n\n");
  for (int i = 0; i < 5; i++) {
    printf("Loading... %d%%\n",i*20);
    sleep(1);
  }
  
  srand(time(0));
  int speed = rand() % 100 + 1;
  printf("\nYou have traveled back to %d at %d%% of the speed of light!\n",year,speed);
  
  int age;
  printf("\nWhat is your age in the current year? ");
  scanf("%d",&age);

  int travelYears = year - 2022;
  int realAge = age + travelYears;
  
  printf("\nYou are now %d years old in the year %d!\n",realAge,year);
  printf("Enjoy your stay in the past... but remember not to change anything!\n");
  
  printf("\nThank you for using the Time Travel Simulator!\n");
  
  return 0;
}