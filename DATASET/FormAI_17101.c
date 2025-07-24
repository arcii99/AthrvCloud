//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_TIME_TRAVEL 20 // maximum allowed time travel in years

int main() {
  int current_year = 2021; // starting year
  int target_year;
  int time_travel_year;
  char yes_no;

  printf("Welcome to the Time Travel Simulator!\n\n");
  printf("Enter the year you want to travel to: ");
  scanf("%d", &target_year); // get input from user

  if (target_year < current_year) { // check if user wants to travel back in time
    printf("Are you sure you want to travel back in time? (y/n)\n");
    scanf(" %c", &yes_no); // get input from user

    if (yes_no == 'n' || yes_no == 'N') { // if user chooses not to travel back in time, exit program
      printf("Exiting program...\n");
      return 0;
    }
  }

  srand(time(NULL)); // seed random number generator

  time_travel_year = rand() % MAX_TIME_TRAVEL + 1; // generate random time travel duration

  if (target_year < current_year) { // if target year is in the past, subtract time travel year from current year
    current_year -= time_travel_year;
    printf("You have traveled %d years back in time!\n", time_travel_year);
  } else { // if target year is in the future, add time travel year to current year
    current_year += time_travel_year;
    printf("You have traveled %d years into the future!\n", time_travel_year);
  }

  printf("Current year is %d\n", current_year); // display current year

  return 0;
}