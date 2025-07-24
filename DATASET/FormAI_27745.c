//FormAI DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  float temperature;
  time_t current_time;
  char* c_time_string;

  // Get the current time
  current_time = time(NULL);

  // Convert to local time format
  c_time_string = ctime(&current_time);

  // Print the current time
  printf("\nCurrent time is %s", c_time_string);

  // Prompt the user to input the temperature
  printf("\nEnter the temperature in Celsius: ");
  scanf("%f", &temperature);

  // Check if the temperature is below freezing point
  if (temperature < 0.0) {
    printf("\nWARNING: Temperature below freezing point!");
  }

  // Check if the temperature is above boiling point
  if (temperature > 100.0) {
    printf("\nWARNING: Temperature above boiling point!");
  }

  // Print the temperature in Celsius
  printf("\nTemperature in Celsius: %.2f", temperature);

  // Convert Celsius to Fahrenheit
  float fahrenheit = (temperature * (9.0/5.0)) + 32;

  // Print the temperature in Fahrenheit
  printf("\nTemperature in Fahrenheit: %.2f", fahrenheit);

  return 0;
}