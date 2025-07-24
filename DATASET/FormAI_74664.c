//FormAI DATASET v1.0 Category: Weather simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MONTHS 12
#define DAYS 31
#define TEMPERATURE_RANGE 20

int main() {
  int year, month, day, temperature;
  srand(time(NULL)); //randomize seed every time

  printf("Welcome to Weather Simulator!\n");
  printf("Enter the year to generate weather data for: ");
  scanf("%d", &year);

  //loop through each month and day
  for (month = 1; month <= MONTHS; month++) {
    printf("\n------------------------\n");
    printf("MONTH %d\n", month);
    printf("------------------------\n");

    for (day = 1; day <= DAYS; day++) {
      //generate a random temperature within a range for each day
      temperature = (rand() % TEMPERATURE_RANGE) - (TEMPERATURE_RANGE / 2);
      printf("%d/%d/%d: %d degrees Celsius\n", day, month, year, temperature);
    }
  }

  printf("\nThanks for using Weather Simulator!\n");
  return 0;
}