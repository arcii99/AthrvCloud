//FormAI DATASET v1.0 Category: Weather simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed the random number generator with current time

  int temperature = rand() % 100; // generate a random temperature between 0-99
  float humidity = ((float) rand() / (float) RAND_MAX) * 100.0; // generate a random humidity value between 0.0-100.0
  int wind_speed = rand() % 50 + 1; // generate a random wind speed between 1-50 mph
  int cloud_coverage = rand() % 100; // generate a random cloud coverage percentage between 0-99

  printf("Today's weather simulation:\n");
  printf("Temperature: %d%cF\n", temperature, 176); 
  printf("Humidity: %.1f%%\n", humidity);
  printf("Wind speed: %d mph\n", wind_speed);
  printf("Cloud coverage: %d%%\n", cloud_coverage);

  // check if temperature is below freezing point
  if (temperature < 32) {
    printf("Warning! There may be ice on the roads!\n");
  }

  // check if humidity is high
  if (humidity > 75) {
    printf("It is very humid today. Don't forget to drink water and stay hydrated!\n");
  }

  // check if wind speed is high
  if (wind_speed > 25) {
    printf("Caution! There may be gusty winds today.\n");
  }

  // check if cloud coverage is heavy
  if (cloud_coverage > 75) {
    printf("Looks like it's going to be a gloomy day.\n");
  }

  return 0;
}