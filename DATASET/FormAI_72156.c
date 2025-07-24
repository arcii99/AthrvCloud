//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdio.h>
#include <time.h>

int main(void) {

  time_t t_now;

  struct tm t_past, t_future;

  // Initial time
  t_past.tm_year = 91;
  t_past.tm_mon = 1;
  t_past.tm_mday = 1;
  t_past.tm_hour = 0;
  t_past.tm_min = 0;
  t_past.tm_sec = 0;

  // Future time
  t_future.tm_year = 121;
  t_future.tm_mon = 0;
  t_future.tm_mday = 1;
  t_future.tm_hour = 0;
  t_future.tm_min = 0;
  t_future.tm_sec = 0;

  // Set initial time
  t_now = mktime(&t_past);

  // Count years from the past to the future
  int years = 0;
  while (t_now < mktime(&t_future)) {
    // Count a year
    t_past.tm_year++;
    years++;

    // Print the year and time
    printf("Year: %d, Time: %s", 1900 + t_past.tm_year, asctime(&t_past));

    // Update current time
    t_now = mktime(&t_past);
  }

  // Print the number of years traveled
  printf("You have traveled %d years into the future!\n", years);

  return 0;
}