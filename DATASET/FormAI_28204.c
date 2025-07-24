//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int year, month, day, hour, minute, second;
  
  printf("Enter current date and time in format yyyy mm dd hh mm ss: ");
  scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &second);

  printf("Enter time travel date and time in format yyyy mm dd hh mm ss: ");
  scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &second);

  struct tm start_time = {0}; // initialize with all zeros
  start_time.tm_year = year - 1900; // tm_year is number of years since 1900
  start_time.tm_mon = month - 1; // tm_mon is zero-based
  start_time.tm_mday = day;
  start_time.tm_hour = hour;
  start_time.tm_min = minute;
  start_time.tm_sec = second;

  time_t start_time_t = mktime(&start_time); // convert to time_t

  printf("You have traveled to %s", ctime(&start_time_t));
  // ctime() formats a time_t value as a string in the form "DOW MON DD HH:MM:SS YYYY\n"
  // Example output: "Tue Aug 31 12:14:01 2021\n"
  
  return 0;
}