//FormAI DATASET v1.0 Category: Weather simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature, humidity, wind_speed, chance_of_rain;
  srand(time(NULL));

  printf("Weather Simulation Program\n");

  for (int i = 1; i < 8; i++) {
    printf("\nDay %d:\n", i);
    temperature = rand() % 40;
    humidity = rand() % 101;
    wind_speed = rand() % 60;
    chance_of_rain = rand() % 101;

    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind speed: %d km/h\n", wind_speed);

    if (chance_of_rain > 50) {
      printf("Chance of rain: %d%% - Bring an umbrella!\n", chance_of_rain);
    } else {
      printf("Chance of rain: %d%% - Enjoy the sunshine!\n", chance_of_rain);
    }
  }

  return 0;
}