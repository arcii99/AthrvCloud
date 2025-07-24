//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t currentTime;
  time(&currentTime);

  printf("Welcome to the Time Travel Simulator program!\n");
  printf("The current time is: %s", ctime(&currentTime));

  // Enter the year you want to travel to
  int year;
  printf("Enter the year you want to travel to: ");
  scanf("%d", &year);
  printf("Traveling to the year %d...\n", year);

  // Time travel simulation
  printf("Initializing time travel simulation...\n");
  printf("3... 2... 1... BOOM!\n");
  printf("Time travel successful! Welcome to the year %d!\n", year);

  // Wait for a few seconds for the user to explore the new year
  printf("Take some time to explore the new year...\n");
  printf("Press enter to continue...");
  getchar();
  getchar();

  // Return to the present day
  time_t returnTime;
  time(&returnTime);

  printf("Returning to the present day...\n");
  printf("3... 2... 1... BOOM!\n");
  printf("Welcome back to the present day!\n");
  printf("The current time is: %s", ctime(&returnTime));

  // Calculate the time difference between the two dates
  double seconds = difftime(returnTime, currentTime);
  printf("You were gone for %.2lf seconds.\n", seconds);

  return 0;
}