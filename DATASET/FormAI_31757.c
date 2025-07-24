//FormAI DATASET v1.0 Category: Weather simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator with current time
  int temperature = rand() % 101; // random temperature between 0 and 100 degrees
  int humidity = rand() % 101; // random humidity percentage
  int windSpeed = rand() % 51; // random wind speed in miles per hour
  int windDirection = rand() % 361; // random wind direction in degrees
  char *weatherType[4] = {"Sunny", "Cloudy", "Rainy", "Windy"}; // array of weather types
  int randomIndex = rand() % 4; // choose random weather type from array

  printf("Today's weather:\n");
  printf("%s\n", weatherType[randomIndex]);
  printf("Temperature: %d degrees Fahrenheit\n", temperature);
  printf("Humidity: %d%%\n", humidity);
  printf("Wind Speed: %d mph\n", windSpeed);
  printf("Wind Direction: %d degrees\n", windDirection);

  return 0;
}