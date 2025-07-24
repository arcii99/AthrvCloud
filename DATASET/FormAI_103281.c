//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm *time_info;

  time(&current_time);
  time_info = localtime(&current_time);

  printf("Current time: %s", asctime(time_info));

  // Travel back to 1990
  time_info->tm_year = 90;
  time_info->tm_mon = 0;
  time_info->tm_mday = 1;
  mktime(time_info);

  printf("Welcome to 1990!\n");
  printf("The date is: %s", asctime(time_info));

  // Travel forward 50 years
  time_info->tm_year += 50;
  mktime(time_info);

  printf("Welcome to 2040!\n");
  printf("The date is: %s", asctime(time_info));

  return 0;
}