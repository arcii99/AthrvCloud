//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int current_year, year_to_travel;
  time_t now;

  /* Get the current date */
  time(&now);
  struct tm *local = localtime(&now);
  current_year = local->tm_year + 1900;

  /* Prompt the user for the desired year to travel to */
  printf("Enter a year to travel to: ");
  scanf("%d", &year_to_travel);

  /* Determine the number of years to travel */
  int years_to_travel = year_to_travel - current_year;

  /* Check if the user wants to travel back in time or forward in time */
  char *verb;
  if (years_to_travel < 0) {
    verb = "went back";
    years_to_travel *= -1;
  } else {
    verb = "went forward";
  }

  /* Print the time travel message */
  printf("\nYou %s in time by %d years.\n\n", verb, years_to_travel);

  /* Simulate the time travel */
  int i;
  for (i = 0; i < years_to_travel; i++) {
    current_year += (verb == "went back") ? -1 : 1;
    printf("Year: %d\n", current_year);
  }

  return 0;
}