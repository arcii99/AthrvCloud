//FormAI DATASET v1.0 Category: Weather simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  // Initialize random number generator
  srand(time(NULL));
  
  // Define variables for temperature, humidity, and precipitation
  float temperature = 0.0;
  float humidity = 0.0;
  float precipitation = 0.0;
  
  // Generate random weather data
  temperature = (rand() % 50) - 10; // Temperature between -10 and 40 degrees Celsius
  humidity = (rand() % 100) / 100.0; // Humidity between 0 and 1
  precipitation = (rand() % 101) / 100.0; // Precipitation between 0 and 1
  
  // Print the weather data
  printf("Temperature: %.1f degrees Celsius\n", temperature);
  printf("Humidity: %.2f\n", humidity);
  printf("Precipitation: %.2f\n", precipitation);
  
  // Determine the weather condition based on the data
  char* weatherCondition = "";
  if (precipitation > 0.5) {
    weatherCondition = "Rainy";
  } else if (temperature < 0) {
    weatherCondition = "Snowy";
  } else if (temperature > 30 && humidity > 0.8) {
    weatherCondition = "Humid and sunny";
  } else if (temperature > 25) {
    weatherCondition = "Hot and sunny";
  } else {
    weatherCondition = "Sunny";
  }
  
  // Print the weather condition
  printf("Weather condition: %s\n", weatherCondition);
  
  return 0;
}