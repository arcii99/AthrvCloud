//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: ultraprecise
#include <stdio.h>
#include <time.h>

int main() {
  struct tm start_time = {0};

  start_time.tm_year = 2021 - 1900; // January 1 2021
  start_time.tm_mon = 0;
  start_time.tm_mday = 1;

  time_t current_time = mktime(&start_time);

  struct tm dest_time = {0};
  dest_time.tm_year = 5500 - 1900; // The year 5500
  dest_time.tm_mon = 0;
  dest_time.tm_mday = 1;

  time_t dest_timestamp = mktime(&dest_time);

  printf("Starting from January 1, 2021, we will travel through time to the year 5500.\n");

  while (current_time < dest_timestamp) {
    printf("Time Traveling to the year: %d\n", 1900 + dest_time.tm_year);
    current_time += 86400; // Add one day
    struct tm* updated_time = localtime(&current_time);
    printf("Date is now: %d-%02d-%02d\n", 1900 + updated_time->tm_year, updated_time->tm_mon + 1, updated_time->tm_mday);
    printf("====================================\n");
  }

  printf("Time Traveling Complete.\n");

  return 0;
}