//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>

int main()
{
  time_t current_time;
  struct tm * time_info;
  char time_str[80];

  time(&current_time);
  time_info = localtime(&current_time);

  printf("Current time: %s\n", asctime(time_info));

  time_info->tm_year = 1955 - 1900; // Set year to 1955
  time_info->tm_mon = 11;           // Set month to December
  time_info->tm_mday = 5;           // Set day to 5
  time_info->tm_hour = 9;           // Set hour to 9:00 AM
  time_info->tm_min = 0;
  time_info->tm_sec = 0;

  current_time = mktime(time_info);

  time_info = localtime(&current_time);

  printf("Destination time: %s\n", asctime(time_info));

  return 0;
}