//FormAI DATASET v1.0 Category: Date and time ; Style: bold
#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time;
  char* c_time_string;

  // Obtain current time
  current_time = time(NULL);

  // Convert to local time format
  c_time_string = ctime(&current_time);

  // Print the current date and time
  printf("\033[1mCurrent date and time:\033[0m %s", c_time_string);

  struct tm *local_time;
  int year, month, day, hour, minute, second;

  // Convert to local time structure
  local_time = localtime(&current_time);

  // Extract individual date and time components
  year = local_time->tm_year + 1900;
  month = local_time->tm_mon + 1;
  day = local_time->tm_mday;
  hour = local_time->tm_hour;
  minute = local_time->tm_min;
  second = local_time->tm_sec;

  // Print the date and time components
  printf("\n\033[1mDate:\033[0m %02d/%02d/%d", day, month, year);
  printf("\n\033[1mTime:\033[0m %02d:%02d:%02d", hour, minute, second);

  // Example of adding one day to the current date
  struct tm future_time = *local_time;
  future_time.tm_mday += 1;
  mktime(&future_time);

  // Print the date one day in the future
  printf("\n\n\033[1mDate one day in the future:\033[0m %02d/%02d/%d\n", future_time.tm_mday, future_time.tm_mon + 1, future_time.tm_year + 1900);

  return 0;
}