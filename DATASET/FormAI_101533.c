//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // set the current time
  time_t current_time = time(NULL);

  // create struct tm for current time
  struct tm *current_tm = localtime(&current_time);

  // initialize variables for travel year and month
  int travel_year, travel_month;

  // prompt user input for travel year and month
  printf("Welcome to the Time Travel Simulator!\n");
  printf("Enter the year you wish to travel to (between 1900 and 2100): ");
  scanf("%d", &travel_year);
  printf("Enter the month you wish to travel to (1-12): ");
  scanf("%d", &travel_month);

  // calculate the difference between current year and travel year
  int year_diff = travel_year - current_tm->tm_year - 1900;

  // calculate the difference between current month and travel month
  int month_diff = travel_month - current_tm->tm_mon - 1;

  // calculate the total time difference in seconds
  time_t time_diff = year_diff * 31536000 + month_diff * 2592000;

  // calculate the travel time based on the current time and time difference
  time_t travel_time = current_time + time_diff;

  // create struct tm for travel time
  struct tm *travel_tm = localtime(&travel_time);

  // print the travel time to the user
  printf("\nTime Travel Successful!\n");
  printf("Current Time: %s", asctime(current_tm));
  printf("Travel Time: %s", asctime(travel_tm));

  return 0;
}