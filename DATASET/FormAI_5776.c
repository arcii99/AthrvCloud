//FormAI DATASET v1.0 Category: Weather simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int temperature = 70;
  int humidity = 75;
  int pressure = 1013;
  int wind_speed = 10;
  int cloud_cover = 50;

  printf("Welcome to the Weather Simulator\n\n");

  printf("Today's weather conditions are as follows:\n");
  printf("Temperature: %d°F\n", temperature);
  printf("Humidity: %d%%\n", humidity);
  printf("Pressure: %d hPa\n", pressure);
  printf("Wind Speed: %d mph\n", wind_speed);
  printf("Cloud Cover: %d%%\n", cloud_cover);

  printf("\nSimulating weather for the next 24 hours...\n\n");

  srand(time(NULL));
  int i;
  for (i = 1; i <= 24; i++) {

    int temperature_change = (rand() % 5) - 2; // change temperature by +/- 2 degrees Fahrenheit
    temperature += temperature_change;
    if (temperature < 0) {
      temperature = 0;
    } else if (temperature > 100) {
      temperature = 100;
    }

    int humidity_change = (rand() % 5) - 2; // change humidity by +/- 2 percent
    humidity += humidity_change;
    if (humidity < 0) {
      humidity = 0;
    } else if (humidity > 100) {
      humidity = 100;
    }

    int pressure_change = (rand() % 5) - 2; // change pressure by +/- 2 hPa
    pressure += pressure_change;
    if (pressure < 900) {
      pressure = 900;
    } else if (pressure > 1100) {
      pressure = 1100;
    }

    int wind_speed_change = (rand() % 5) - 2; // change wind speed by +/- 2 mph
    wind_speed += wind_speed_change;
    if (wind_speed < 0) {
      wind_speed = 0;
    } else if (wind_speed > 50) {
      wind_speed = 50;
    }

    int cloud_cover_change = (rand() % 5) - 2; // change cloud cover by +/- 2 percent
    cloud_cover += cloud_cover_change;
    if (cloud_cover < 0) {
      cloud_cover = 0;
    } else if (cloud_cover > 100) {
      cloud_cover = 100;
    }

    printf("Hour %d: Temperature: %d°F, Humidity: %d%%, Pressure: %d hPa, Wind Speed: %d mph, Cloud Cover: %d%%\n",
           i, temperature, humidity, pressure, wind_speed, cloud_cover);

  }

  return 0;
}