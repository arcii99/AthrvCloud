//FormAI DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature, humidity, wind_speed, is_raining;
  srand(time(NULL)); // set seed for random function

  // Generate weather parameters
  temperature = rand() % 50; // generate temperature between 0 and 49 degrees Celsius
  humidity = rand() % 100; // generate humidity between 0 and 99%
  wind_speed = rand() % 100; // generate wind speed between 0 and 99 km/hour

  // Determine if it's raining or not
  if (humidity > 80 && temperature > 0) { // if humidity above 80% and temperature above freezing point
    is_raining = 1; // it's raining
  } else {
    is_raining = 0; // it's not raining
  }

  // Display weather conditions
  printf("Today's weather conditions:\n");
  printf("Temperature: %d degrees Celsius\n", temperature);
  printf("Humidity: %d%%\n", humidity);
  printf("Wind speed: %d km/hour\n", wind_speed);

  // Determine what to wear based on weather conditions
  printf("What to wear:\n");
  if (temperature > 35) {
    printf("Wear light clothing and a hat\n");
  } else if (temperature > 25) {
    printf("Wear light clothing\n");
  } else if (temperature > 15) {
    printf("Wear a light jacket\n");
  } else if (temperature > 5) {
    printf("Wear a jacket and a hat\n");
  } else {
    printf("Wear a heavy coat, gloves, and a hat\n");
  }

  // Determine if it's safe to drive based on weather conditions
  printf("Is it safe to drive?\n");
  if (wind_speed > 80 && temperature < -10) {
    printf("It's not safe to drive due to strong winds and freezing temperatures\n");
  } else if (wind_speed > 80) {
    printf("It's not safe to drive due to strong winds\n");
  } else if (temperature < -10) {
    printf("It's not safe to drive due to freezing temperatures\n");
  } else {
    printf("It's safe to drive\n");
  }

  // Determine if it's a good idea to go outside based on weather conditions
  printf("Is it a good idea to go outside?\n");
  if (is_raining && temperature < 5) {
    printf("It's not a good idea to go outside due to rain and freezing temperatures\n");
  } else if (is_raining) {
    printf("It's not a good idea to go outside due to rain\n");
  } else if (temperature < 5) {
    printf("It's not a good idea to go outside due to freezing temperatures\n");
  } else {
    printf("It's a good idea to go outside\n");
  }

  return 0;
}