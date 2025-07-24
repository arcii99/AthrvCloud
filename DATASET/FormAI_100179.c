//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm *time_info;
  char date_string[20];

  time(&current_time);
  time_info = localtime(&current_time);

  printf("Current date and time: %s", asctime(time_info));
  printf("Enter the year that you would like to travel to: ");
  int year;
  scanf("%d", &year);

  time_info->tm_year = year - 1900; // set year
  time_info->tm_mon = 0; // set month to January
  time_info->tm_mday = 1; // set day to the first

  mktime(time_info); // update time with new values

  strftime(date_string, sizeof(date_string), "%Y-%m-%d", time_info);
  printf("Traveling to date: %s\n", date_string);

  // Let's simulate time travel by waiting for 5 seconds
  sleep(5);

  // Print the new date and time after time travel
  time(&current_time);
  time_info = localtime(&current_time);
  strftime(date_string, sizeof(date_string), "%Y-%m-%d", time_info);
  printf("New date and time: %s", asctime(time_info));

  return 0;
}