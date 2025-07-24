//FormAI DATASET v1.0 Category: Weather simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  // Declare variables
  int temperature, windSpeed, humidity, pollenCount, rainfall;
  int i, j, k;
  
  // Set seed for random number generator
  srand(time(NULL));
  
  // Generate random values for weather conditions
  temperature = rand() % 30 + 1;
  windSpeed = rand() % 50 + 1;
  humidity = rand() % 100 + 1;
  pollenCount = rand() % 500 + 1;
  rainfall = rand() % 20 + 1;
  
  // Display weather conditions
  printf("\nToday's Weather Conditions\n");
  printf("----------------------------\n");
  printf("Temperature: %dC\n", temperature);
  printf("Wind Speed: %dmph\n", windSpeed);
  printf("Humidity: %d%%\n", humidity);
  printf("Pollen Count: %d\n", pollenCount);
  printf("Rainfall: %dmm\n\n", rainfall);
  
  // Simulate weather forecast for the next 5 days
  printf("5-day Weather Forecast\n");
  printf("------------------------\n");
  
  for(i = 1; i <= 5; i++) {
    // Generate random values for weather conditions
    temperature = rand() % 30 + 1;
    windSpeed = rand() % 50 + 1;
    humidity = rand() % 100 + 1;
    pollenCount = rand() % 500 + 1;
    rainfall = rand() % 20 + 1;
    
    // Display weather conditions for the day
    printf("Day %d:\n", i);
    printf("--------\n");
    printf("Temperature: %dC\n", temperature);
    printf("Wind Speed: %dmph\n", windSpeed);
    printf("Humidity: %d%%\n", humidity);
    printf("Pollen Count: %d\n", pollenCount);
    printf("Rainfall: %dmm\n\n", rainfall);
    
    // Simulate hourly weather forecast for the day
    printf("Hourly Weather Forecast for Day %d\n", i);
    printf("------------------------------------\n");
    
    for(j = 0; j <= 23; j++) {
      // Generate random values for weather conditions
      temperature = rand() % 30 + 1;
      windSpeed = rand() % 50 + 1;
      humidity = rand() % 100 + 1;
      pollenCount = rand() % 500 + 1;
      rainfall = rand() % 20 + 1;
      
      // Display weather conditions for the hour
      printf("Hour %d: ", j);
      for(k = 0; k <= (windSpeed / 5); k++) {
        printf("*");
      }
      printf("\n");
      printf("          Temperature: %dC\n", temperature);
      printf("          Wind Speed: %dmph\n", windSpeed);
      printf("          Humidity: %d%%\n", humidity);
      printf("          Pollen Count: %d\n", pollenCount);
      printf("          Rainfall: %dmm\n\n", rainfall);
    }
  }
  
  return 0;
}