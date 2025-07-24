//FormAI DATASET v1.0 Category: Date and time ; Style: minimalist
#include <stdio.h>
#include <time.h>

int main() {
  // get the current time
  time_t raw_time;
  struct tm *time_info;
  time(&raw_time);
  time_info = localtime(&raw_time);

  // format the date and time
  char date_time[50];
  strftime(date_time, sizeof(date_time), "%A, %d %B %Y %H:%M:%S %Z", time_info);

  // print the date and time
  printf("The current date and time is: %s\n", date_time);

  return 0;
}