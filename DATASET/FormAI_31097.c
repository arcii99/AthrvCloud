//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t t = time(NULL); // get current time
  struct tm *now = localtime(&t); // convert to local time
  int startYear = 1900; // set starting year
  int endYear = now->tm_year + 1900; // set current year as end year
  int years = endYear - startYear; // calculate total number of years
  srand(time(NULL)); // initialize random number generator
  int randYear = rand() % years + startYear; // generate random year within range
  printf("Welcome to the Time Travel Simulator!\n\n");
  printf("You will be transported to a random year between %d and %d.\n", startYear, endYear);
  printf("Are you ready? (y/n): ");
  char response = getchar();
  if (response == 'y') {
    printf("\nTraveling to %d...\n\n", randYear);
    // TODO: simulate time travel
    printf("You have arrived in %d!\n", randYear);
  } else {
    printf("\nOkay, maybe next time.\n");
  }
  return 0;
}