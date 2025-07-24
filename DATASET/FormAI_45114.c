//FormAI DATASET v1.0 Category: Temperature monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  float temperature, highest_temp = -100.0f, lowest_temp = 100.0f, avg_temp = 0.0f;
  int i, num_of_days;

  srand(time(0)); // Set a seed for the random number generator

  printf("Enter the number of days to monitor the temperature: ");
  scanf("%d", &num_of_days);

  if (num_of_days < 1) {
    printf("Invalid input. Number of days must be at least 1.\n");
    return 0;
  }

  printf("\nTemperature Monitor\n");
  printf("-------------------\n");

  for (i = 1; i <= num_of_days; i++) {
    temperature = (float)(rand() % 50) - 10.0f; // Generate a random temperature between -10 and 40 degrees Celsius
    printf("Day %d: %.1f degrees Celsius\n", i, temperature);

    if (temperature > highest_temp) {
      highest_temp = temperature;
    }

    if (temperature < lowest_temp) {
      lowest_temp = temperature;
    }

    avg_temp += temperature;
  }

  avg_temp /= num_of_days;

  printf("\nHighest temperature: %.1f degrees Celsius\n", highest_temp);
  printf("Lowest temperature: %.1f degrees Celsius\n", lowest_temp);
  printf("Average temperature: %.1f degrees Celsius\n", avg_temp);

  return 0;
}