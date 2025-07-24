//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: innovative
#include <stdio.h>
#include <time.h>

int main() {
  // Get the current time
  time_t current_time;
  time(&current_time);

  // Print the current time
  printf("The current time is %s\n", ctime(&current_time));

  // Create a time struct for the year 2050
  struct tm future_time;
  future_time.tm_year = 150; // years since 1900, so 2050 is year 150
  future_time.tm_mday = 1; // set the day to the 1st of the month
  future_time.tm_mon = 0; // January is month 0
  future_time.tm_hour = 0;
  future_time.tm_min = 0;
  future_time.tm_sec = 0;

  // Convert the time struct to a time_t
  time_t future_time_t = mktime(&future_time);
  printf("The time traveler has arrived on %s\n", ctime(&future_time_t));

  // Calculate the time difference between the current time and the future time
  int time_difference = difftime(future_time_t, current_time);

  // Print the time difference
  printf("The time traveler traveled through time %d seconds\n", time_difference);

  // Create a time struct for the year 1800
  struct tm past_time;
  past_time.tm_year = -50; // years since 1900, so 1800 is year -50
  past_time.tm_mday = 1; // set the day to the 1st of the month
  past_time.tm_mon = 0; // January is month 0
  past_time.tm_hour = 0;
  past_time.tm_min = 0;
  past_time.tm_sec = 0;

  // Convert the time struct to a time_t
  time_t past_time_t = mktime(&past_time);
  printf("The time traveler has arrived on %s\n", ctime(&past_time_t));

  // Calculate the time difference between the current time and the past time
  time_difference = difftime(past_time_t, current_time);

  // Print the time difference
  printf("The time traveler traveled through time %d seconds\n", time_difference);

  return 0;
}