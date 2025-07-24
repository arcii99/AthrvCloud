//FormAI DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  // set seed for randomization
  srand(time(NULL));
  
  // initialize variables
  int temperature, humidity, wind;
  
  // generate random values for temperature, humidity, and wind
  temperature = rand() % 101 - 40;
  humidity = rand() % 101;
  wind = rand() % 61 - 30;
  
  // print current weather conditions
  printf("Current weather conditions:\n");
  printf("Temperature: %d degrees Celsius\n", temperature);
  printf("Humidity: %d%%\n", humidity);
  printf("Wind speed: %d km/h\n", wind);
  
  // determine weather forecast based on temperature, humidity, and wind
  if (temperature >= 30 && humidity >= 70 && wind >= 40) {
    printf("There is a high chance of a thunderstorm today.\n");
  } else if (temperature >= 25 && humidity >= 60 && wind >= 30) {
    printf("There is a moderate chance of a thunderstorm today.\n");
  } else if (temperature >= 20 && humidity >= 50 && wind >= 20) {
    printf("There is a low chance of a thunderstorm today.\n");
  } else if (temperature < 0) {
    printf("There is a high chance of snow today.\n");
  } else if (temperature < 10 && humidity > 70 && wind > 30) {
    printf("There is a moderate chance of snow today.\n");
  } else if (humidity > 80 && wind < 10) {
    printf("There is a high chance of fog today.\n");
  } else {
    printf("There are no extreme weather conditions to report today.\n");
  }
  
  return 0;
}