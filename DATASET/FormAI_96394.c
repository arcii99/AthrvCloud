//FormAI DATASET v1.0 Category: Temperature monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum temperature as 100 degree celcius
#define MAX_TEMPERATURE 100

int main() {
  int temperature;

  // Get temperature input from user
  printf("Please enter temperature in degree celcius: ");
  scanf("%d", &temperature);

  // Check if temperature exceeds maximum temperature
  if (temperature > MAX_TEMPERATURE) {
    printf("Error: Temperature exceeds the maximum limit of %d degree celcius.", MAX_TEMPERATURE);
    return 0;
  }

  // Print temperature details
  printf("\nTemperature: %d degree celcius\n", temperature);

  // Check if temperature is below freezing point
  if (temperature < 0) {
    printf("Warning: Temperature is below freezing point.\n");
  }

  // Check if temperature is within normal range
  if (temperature >= 0 && temperature <= 37) {
    printf("Normal body temperature.\n");
  }

  // Check if temperature is above normal range
  if (temperature > 37 && temperature <= 38) {
    printf("Low-grade fever.\n");
  }

  // Check if temperature is high-grade fever
  if (temperature > 38) {
    printf("High-grade fever.\n");
  }

  return 0;
}