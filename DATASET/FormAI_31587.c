//FormAI DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>

int main() {
  float current_temperature = 0.0;
  float previous_temperature = 0.0;
  
  // Ask for current temperature
  printf("Enter current temperature in Celsius: ");
  scanf("%f", &current_temperature);

  // Check if temperature increased or decreased
  if (current_temperature > previous_temperature) {
    printf("Temperature increased by %.1f degrees Celsius\n", current_temperature - previous_temperature);
  }
  else if (current_temperature < previous_temperature) {
    printf("Temperature decreased by %.1f degrees Celsius\n", previous_temperature - current_temperature);
  }
  else {
    printf("Temperature remains the same\n");
  }

  // Store current temperature for future reference
  previous_temperature = current_temperature;

  return 0;
}