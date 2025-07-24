//FormAI DATASET v1.0 Category: Date and time ; Style: introspective
#include <stdio.h>
#include <time.h>

int main()
{
  time_t current_time;
  struct tm * time_info;
  char time_string[9]; /* space for "HH:MM:SS\0" */

  time(&current_time);
  time_info = localtime(&current_time);

  strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
  printf("Current Time: %s\n", time_string);

  return 0;
}