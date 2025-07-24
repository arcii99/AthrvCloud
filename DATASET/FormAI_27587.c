//FormAI DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>

int main() {
  float temperature;
  int hour;

  printf("Welcome to the Temperature Monitor Program\n");

  for (hour = 0; hour < 24; hour++) {
    printf("Enter the temperature for hour %d: ", hour);

    if (scanf("%f", &temperature) != 1) {
      printf("Invalid input, program terminated\n");
      return 1;
    }

    if (temperature < -273.15f) {
      printf("Temperature cannot be less than absolute zero, program terminated\n");
      return 1;
    }

    printf("Temperature for hour %d is %.2fC\n", hour, temperature);
  }

  printf("Data collection completed, program terminated\n");

  return 0;
}