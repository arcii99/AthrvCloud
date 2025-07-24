//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm *time_info;
  char time_string[25];

  // Get user input for how many years to travel back in time
  int years_travelled;
  printf("How many years back in time would you like to go? ");
  scanf("%d", &years_travelled);

  // Get current time
  time(&current_time);
  time_info = localtime(&current_time);

  // Calculate the time travelled back in time
  time_info->tm_year -= years_travelled;
  mktime(time_info);

  // Format time string
  strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

  // Display the time travelled to
  printf("You have travelled %d years back in time. Welcome to %s!\n", years_travelled, time_string);

  return 0;
}