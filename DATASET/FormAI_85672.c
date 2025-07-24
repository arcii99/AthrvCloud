//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  time_t current_time = time(NULL); // get the current time
  struct tm *local_time = localtime(&current_time); // Convert the current time to local time
  printf("Current time: %s", asctime(local_time)); // Print the current time

  srand(time(NULL)); // Set the seed for random number generation

  int years_to_travel = rand() % 100; // Generate a random number of years to travel

  int travel_direction;
  printf("Enter 1 to travel forward in time or -1 to travel backwards: ");
  scanf("%d", &travel_direction); // Ask the user which direction they want to travel in time

  if (travel_direction == 1) { // Traveling forward in time

    local_time->tm_year += years_to_travel; // Add the random number of years to the year value in the time struct
    
    mktime(local_time); // Convert the time struct back to time_t format
    
    printf("You have traveled %d years into the future.\n", years_to_travel);
    
  } else if (travel_direction == -1) { // Traveling backwards in time

    local_time->tm_year -= years_to_travel; // Subtract the random number of years from the year value in the time struct
    
    mktime(local_time); // Convert the time struct back to time_t format

    printf("You have traveled %d years into the past.\n", years_to_travel);
    
  } else { // Invalid direction input

    printf("Invalid direction input.\n");
    return 1;
    
  }

  printf("New time: %s", asctime(local_time)); // Print the new time value

  return 0;
}