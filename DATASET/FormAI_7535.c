//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  time_t currentTime;
  struct tm* timeInfo;
  char timeString[100];

  printf("Welcome to the Time Travel Simulator!\n\n");

  // Get the current time and display it
  time(&currentTime);
  timeInfo = localtime(&currentTime);

  strftime(timeString, 100, "%H:%M:%S on %A, %B %d, %Y", timeInfo);
  printf("The current time is %s\n\n", timeString);

  // Ask the user for a year to travel to 
  printf("Enter a year to travel to: ");
  int targetYear;
  scanf("%d", &targetYear);

  // Check if it's a valid year (between 1900 and 2100)
  if (targetYear < 1900 || targetYear > 2100) {
    printf("Invalid year. Please enter a year between 1900 and 2100.\n");
    return 1;
  }

  // Calculate the time difference in seconds
  int secondsPerYear = 365 * 24 * 60 * 60; // 365 days * 24 hours * 60 minutes * 60 seconds
  int timeDifference = (targetYear - 1900) * secondsPerYear;

  // Add/subtract the time difference and display the new time
  currentTime += timeDifference;
  timeInfo = localtime(&currentTime);
  strftime(timeString, 100, "%H:%M:%S on %A, %B %d, %Y", timeInfo);
  printf("The time in %d is %s\n", targetYear, timeString);

  return 0;
}