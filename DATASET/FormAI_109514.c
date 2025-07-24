//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Get the current time
  time_t now = time(NULL);
  printf("The current time is: %s", ctime(&now));

  // Ask the user to enter a year
  int year;
  printf("Enter a year to travel to: ");
  scanf("%d", &year);

  // Calculate the number of seconds to travel
  struct tm future_time = {0};
  future_time.tm_year = year - 1900;
  time_t future_secs = mktime(&future_time);
  double seconds_to_travel = difftime(future_secs, now);

  // Check that the year entered is in the future
  if (seconds_to_travel <= 0) {
    printf("Sorry, you can only travel to the future.\n");
    return 1;
  }

  // Ask the user to enter a time travel speed
  int speed;
  printf("Enter a time travel speed (seconds per second): ");
  scanf("%d", &speed);

  // Calculate the time it will take to travel
  double travel_time = seconds_to_travel / speed;

  // Print the results
  printf("Time travel successful!\n");
  printf("You have arrive %d years in the future.\n", year - 2021);
  printf("Your journey took %.2f seconds in real time.\n", travel_time);

  return 0;
}