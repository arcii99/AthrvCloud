//FormAI DATASET v1.0 Category: Weather simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // Set the random seed for simulation
  srand(time(NULL));
  
  // Simulation variables
  int temperature = 0;
  int humidity = 0;
  int pressure = 0;
  int windSpeed = 0;
  int cloudCover = 0;

  printf("Begin Weather Simulation:\n");

  // Generate weather data for ten iterations
  for(int i = 0; i < 10; i++) {
    // Generate random values for weather variables
    temperature = rand() % 50;
    humidity = rand() % 100;
    pressure = rand() % 150 + 850;
    windSpeed = rand() % 50;
    cloudCover = rand() % 100;

    printf("\nWeather Data for Iteration %d:\n", i+1);
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Pressure: %d hPa\n", pressure);
    printf("Wind Speed: %d km/h\n", windSpeed);
    printf("Cloud Cover: %d%%\n", cloudCover);

    // Generate weather conditions based on variables
    if (temperature > 30 && humidity > 70) {
      printf("Condition: Hot and Humid\n");
    } else if (temperature > 30 && windSpeed > 40) {
      printf("Condition: Hot and Windy\n");
    } else if (pressure < 1000) {
      printf("Condition: Low Pressure\n");
    } else if (cloudCover > 70) {
      printf("Condition: Overcast\n");
    } else {
      printf("Condition: Normal\n");
    }

  }

  printf("\nEnd Weather Simulation.");
  
  return 0;
}