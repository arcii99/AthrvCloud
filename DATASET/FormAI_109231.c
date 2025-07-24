//FormAI DATASET v1.0 Category: Weather simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Initialize random seed

  // Declare variables
  int temperature, humidity, wind_speed;
  char weather[10];

  // Generate random values for weather variables
  temperature = rand() % 20 + 10; // Temperature between 10°C and 30°C
  humidity = rand() % 50 + 50;   // Humidity between 50% and 100%
  wind_speed = rand() % 30 + 1;  // Wind speed between 1 km/h and 30 km/h

  // Determine weather condition based on temperature and humidity
  if (temperature >= 25 && humidity >= 70) {
    strcpy(weather, "Hot and humid");
  } else if (temperature >= 20 && humidity >= 50) {
    strcpy(weather, "Warm and humid");
  } else if (temperature >= 15) {
    strcpy(weather, "Cool");
  } else {
    strcpy(weather, "Cold");
  }

  // Print current weather conditions
  printf("Temperature: %d°C\n", temperature);
  printf("Humidity: %d%%\n", humidity);
  printf("Wind speed: %d km/h\n", wind_speed);
  printf("Weather: %s\n", weather);

  return 0;
}