//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int current_year, future_year;
  time_t current_time;
  struct tm *current_tm;

  // Get the current year
  current_time = time(NULL);
  current_tm = localtime(&current_time);
  current_year = current_tm->tm_year + 1900;

  // Get the future year from user input
  printf("Enter a future year: ");
  scanf("%d", &future_year);

  // Calculate the time difference
  int years_difference = future_year - current_year;
  int days_difference = years_difference * 365;
  int hours_difference = days_difference * 24;

  // Print the time difference
  printf("Time difference: %d years, %d days, %d hours\n", years_difference, days_difference, hours_difference);

  // Travel to the future
  printf("Welcome to the year %d!\n", future_year);

  // Randomly generate an event
  srand(time(NULL));
  int event = rand() % 4;
  switch(event) {
    case 0:
      printf("The world is now at peace.\n");
      break;
    case 1:
      printf("Scientists have discovered a cure for cancer.\n");
      break;
    case 2:
      printf("Aliens have made contact with Earth.\n");
      break;
    case 3:
      printf("A massive asteroid struck Earth, causing widespread destruction.\n");
      break;
  }

  return 0;
}