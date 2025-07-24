//FormAI DATASET v1.0 Category: Date and time ; Style: minimalist
#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time;
  
  time(&current_time);
  printf("The current date and time is: %s\n", ctime(&current_time));
  
  struct tm *local_time = localtime(&current_time);
  int year = local_time->tm_year + 1900;
  int month = local_time->tm_mon + 1;
  int day = local_time->tm_mday;
  int hour = local_time->tm_hour;
  int minute = local_time->tm_min;
  int second = local_time->tm_sec;
  
  printf("The current date is: %02d/%02d/%04d\n", day, month, year);
  printf("The current time is: %02d:%02d:%02d\n", hour, minute, second);
  
  return 0;
}