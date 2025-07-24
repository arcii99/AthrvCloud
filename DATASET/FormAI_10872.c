//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  // Let's set up the time machine
  int currentYear = 2021;
  int maxYear = 2100;
  int targetYear;
  
  // Time travel menu
  printf("Welcome to the Time Travel Simulator!\n");
  printf("-------------------------------------\n");
  printf("Enter the year you want to travel to (between %d and %d):\n", currentYear, maxYear);
  scanf("%d", &targetYear);
  
  // Check if the target year is valid
  if (targetYear < currentYear || targetYear > maxYear) {
    printf("Invalid input. Please enter a year between %d and %d.\n", currentYear, maxYear);
    return 0;
  }
  
  // Time travel sequence
  int currentMonth = 1;
  int currentDay = 1;
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  
  // Time travel loop
  while (tm.tm_year + 1900 < targetYear) {
    printf("The current year is %d.\n", tm.tm_year + 1900);
    tm.tm_year += 1;
    tm.tm_yday += 365;
    if ((tm.tm_year + 1900) % 4 == 0) {
      if ((tm.tm_year + 1900) % 100 == 0 && (tm.tm_year + 1900) % 400 != 0) {
        tm.tm_yday -= 1;
      } else {
        tm.tm_yday += 1;
      }
    }
  }
  
  // Print the final date
  printf("You have arrived in the year %d on %d/%d/%d.\n", tm.tm_year + 1900, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
  
  return 0;
}