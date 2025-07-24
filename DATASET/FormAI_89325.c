//FormAI DATASET v1.0 Category: Weather simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature, humidity, wind_speed, weather_condition;
  srand(time(NULL));

  temperature = rand() % 50;
  humidity = rand() % 100;
  wind_speed = rand() % 20;

  // 0: sunny, 1: cloudy, 2: rainy, 3: snowy
  weather_condition = rand() % 4;

  printf("Temperature: %d degrees Celsius\n", temperature);
  printf("Humidity: %d percent\n", humidity);
  printf("Wind Speed: %d km/h\n", wind_speed);

  switch(weather_condition) {
    case 0:
      printf("Weather Condition: Sunny\n");
      break;

    case 1:
      printf("Weather Condition: Cloudy\n");
      break;

    case 2:
      printf("Weather Condition: Rainy\n");
      break;

    case 3:
      printf("Weather Condition: Snowy\n");
      break;

    default:
      printf("Weather Condition: Unknown\n");
      break;
  }

  return 0;
}