//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t t;
  struct tm *timeinfo;
  char timestamp[80];

  time(&t); //get current time
  timeinfo = localtime(&t); //convert to local time

  //print current time
  strftime(timestamp, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
  printf("Current Time: %s\n", timestamp);

  printf("\nWelcome to the Time Travel Simulator!\n");
  printf("Enter a date (YYYY-MM-DD): ");
  scanf("%s", timestamp);

  // convert string to time
  strptime(timestamp, "%Y-%m-%d", timeinfo);

  time_t travel_time = mktime(timeinfo); // convert to time_t

  double seconds_diff = difftime(travel_time, t); // difference in seconds
  int years_diff = seconds_diff / (60 * 60 * 24 * 365); // difference in years

  printf("\nTraveling to %s...\n", timestamp);
  printf("Time difference from current time: %d years\n\n", abs(years_diff));
  
  // Simulate travel by printing out the years in between
  int current_year = timeinfo->tm_year + 1900;
  int travel_year = current_year - years_diff;

  printf("Traveling...\n");
  for (int i = current_year - 1; i >= travel_year; i--) {
    printf("%d\n", i);
  }

  printf("\nArrived at %s!\n", timestamp);
 
  return 0;
}