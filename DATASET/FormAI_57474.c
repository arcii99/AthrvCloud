//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Set up random seed
  srand(time(NULL));
  // Define time machine destination
  int year_destination = rand() % 2022;
  // Define current year
  int current_year = 2022;
  // Display time machine destination
  printf("Your destination year is: %d\n", year_destination);
  // Determine if time machine travels forward or backward in time
  int time_direction = (rand() % 2 == 0) ? 1 : -1;
  
  if (year_destination == current_year) {
    printf("You have already arrived at your destination!\n");
    return 0;
  } else if (year_destination > current_year) {
    printf("You are travelling forward in time...\n");
  } else {
    printf("You are travelling backward in time...\n");
  }
  // Loop through time until arrival at destination
  for (int i = current_year; i != year_destination; i += time_direction) {
    // Output current year and direction of travel
    printf("Year: %d, Direction: %s\n", i, (time_direction == 1) ? "Forward" : "Backward");
  }
  // Output arrival at destination year
  printf("You have arrived at your destination year of: %d\n", year_destination);
  return 0;
}