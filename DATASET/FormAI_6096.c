//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  time_t startTime = time(NULL);
  struct tm *stopTime = gmtime(&startTime);

  // set the stop time to 100 years in the future
  stopTime->tm_year += 100;

  printf("Welcome to the time travel simulator!\n");
  printf("This program will take you to the year %d.\n\n", stopTime->tm_year + 1900);

  while (difftime(mktime(stopTime), time(NULL)) > 0) {
    printf("The current time is: %s", ctime(&startTime));
    printf("Do you want to travel through time?\n");
    printf("Enter Y for Yes or N for No: ");

    char answer = getchar();

    if (answer == 'Y' || answer == 'y') {
      printf("\nHow far do you want to travel (in years)? ");
      int years;
      scanf("%d", &years);

      // update the start time and stop time
      startTime += (years * 31536000); // 1 year = 31536000 seconds
      stopTime->tm_year += years;
      mktime(stopTime);

      printf("\nYou traveled %d years into the future.\n\n", years);
    } else if (answer == 'N' || answer == 'n') {
      printf("\nExiting time travel simulator...\n");
      exit(0);
    } else {
      printf("\nInvalid input. Please enter Y or N.\n\n");
    }

    // clear input buffer
    while ((getchar()) != '\n');
  }

  printf("\nCongratulations! You made it to the year %d!\n", stopTime->tm_year + 1900);
  printf("Exiting time travel simulator...\n");

  return 0;
}