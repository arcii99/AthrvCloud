//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm *time_info;
  char *time_string;

  time(&current_time);
  time_info = localtime(&current_time);

  printf("Current time: %s", asctime(time_info));

  printf("Enter a year to travel to (format YYYY): ");
  int year;
  scanf("%d", &year);

  if (year <= 1900) {
    printf("Invalid year. You must travel to a year after 1900.\n");
    return 1;
  }

  int years_to_travel = year - (time_info->tm_year + 1900);

  printf("Travelling to the year %d...\n", year);

  if (years_to_travel < 0) {
    printf("You have travelled back in time %d years.\n", -years_to_travel);
  } else {
    printf("You have travelled forward in time %d years.\n", years_to_travel);
  }

  time_info->tm_year += years_to_travel;
  mktime(time_info);
  printf("New date: %s", asctime(time_info));

  return 0;
}