//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <time.h>

#define TRAVEL_YEAR 2099 // The year we travel to
#define TRAVEL_MONTH 7 // The month we travel to
#define TRAVEL_DAY 1 // The day we travel to

int main() {
  
  time_t now = time(NULL); // Get current time
  struct tm travelTime = {0}; // Create struct to hold travel time
  travelTime.tm_year = TRAVEL_YEAR - 1900; // Set year
  travelTime.tm_mon = TRAVEL_MONTH - 1; // Set Month
  travelTime.tm_mday = TRAVEL_DAY; // Set day
  travelTime.tm_hour = 0; // Set hour
  travelTime.tm_min = 0; // Set minute
  travelTime.tm_sec = 0; // Set second
  
  time_t travelSeconds = mktime(&travelTime); // Convert travel time to seconds
  time_t timeDelta = travelSeconds - now; // Calculate time difference
  
  if (timeDelta < 0) { // If the travel time is in the past
    printf("You cannot travel to the past.\n");
    return 1;
  }
  
  printf("You are about to travel to %d/%d/%d. Continue? (Y/N) ", TRAVEL_MONTH, TRAVEL_DAY, TRAVEL_YEAR);
  char confirmation;
  scanf(" %c", &confirmation);
  
  if (confirmation != 'Y') { // If user says no
    printf("Cancelled.\n");
    return 0;
  }
  
  printf("Travelling through time...\n");
  
  for (int i = timeDelta; i >= 0; i--) { // Loop through time difference in seconds
    printf("Seconds remaining: %d\n", i);
  }
  
  printf("You have arrived at %d/%d/%d.\n", TRAVEL_MONTH, TRAVEL_DAY, TRAVEL_YEAR);
  
  return 0;
}