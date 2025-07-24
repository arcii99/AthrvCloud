//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm *time_info;
  char time_string[9];
  
  // Setup current time
  time(&current_time);
  time_info = localtime(&current_time);

  // Display current time
  strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
  printf("Current time is: %s\n", time_string);

  // Set travel time
  time_info->tm_year = 112; // Year 2012
  time_info->tm_mon = 0; // January
  time_info->tm_mday = 1; // First day of the month
  time_info->tm_hour = 0;
  time_info->tm_min = 0;
  time_info->tm_sec = 0;
  mktime(time_info);

  // Display travel time
  strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
  printf("Travel time is: %s\n", time_string);

  // Wait for user to press enter
  printf("Press enter to travel through time...");
  getchar();

  // Travel through time
  current_time = mktime(time_info);
  localtime_r(&current_time, time_info);

  // Display new time
  strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
  printf("You have arrived at: %s\n", time_string);

  return 0;
}