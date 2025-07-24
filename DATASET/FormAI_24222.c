//FormAI DATASET v1.0 Category: Weather simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initializing random seed
  srand(time(NULL));

  // constants for temperature range
  const int MAX_TEMP = 40;
  const int MIN_TEMP = -10;

  // setting initial temperature to a random value
  int current_temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;

  // printing current temperature
  printf("Current temperature: %d\n", current_temp);

  // constants for chance of rain and snow
  const int MAX_CHANCE = 100;
  const int RAIN_CHANCE = 30;
  const int SNOW_CHANCE = 10;

  // setting initial chance of rain and snow to random values
  int rain_chance = rand() % (MAX_CHANCE + 1);
  int snow_chance = rand() % (MAX_CHANCE + 1);

  // printing chance of rain and snow
  printf("Chance of rain: %d%%, Chance of snow: %d%%\n", rain_chance, snow_chance);

  // constants for wind speed range
  const int MAX_WIND_SPEED = 30;
  const int MIN_WIND_SPEED = 0;

  // setting initial wind speed to a random value
  int wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;

  // printing wind speed
  printf("Wind speed: %d km/h\n", wind_speed);

  // constants for humidity range
  const int MAX_HUMIDITY = 100;
  const int MIN_HUMIDITY = 0;

  // setting initial humidity to a random value
  int humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;

  // printing humidity
  printf("Humidity: %d%%\n", humidity);

  // simulating weather changes for 7 days
  for (int i = 1; i <= 7; i++) {
    // generating random values for temperature, chance of rain and snow, wind speed, and humidity
    int temp_change = rand() % 11 - 5;
    int rain_change = rand() % 11 - 5;
    int snow_change = rand() % 11 - 5;
    int wind_change = rand() % 11 - 5;
    int humidity_change = rand() % 11 - 5;

    // updating current temperature
    current_temp += temp_change;

    // making sure temperature stays within allowable range
    if (current_temp > MAX_TEMP) {
      current_temp = MAX_TEMP;
    } else if (current_temp < MIN_TEMP) {
      current_temp = MIN_TEMP;
    }

    // updating chance of rain and snow
    rain_chance += rain_change;
    snow_chance += snow_change;

    // making sure chance of rain and snow stays within allowable range
    if (rain_chance > MAX_CHANCE) {
      rain_chance = MAX_CHANCE;
    } else if (rain_chance < 0) {
      rain_chance = 0;
    }
    if (snow_chance > MAX_CHANCE) {
      snow_chance = MAX_CHANCE;
    } else if (snow_chance < 0) {
      snow_chance = 0;
    }

    // updating wind speed
    wind_speed += wind_change;

    // making sure wind speed stays within allowable range
    if (wind_speed > MAX_WIND_SPEED) {
      wind_speed = MAX_WIND_SPEED;
    } else if (wind_speed < MIN_WIND_SPEED) {
      wind_speed = MIN_WIND_SPEED;
    }

    // updating humidity
    humidity += humidity_change;

    // making sure humidity stays within allowable range
    if (humidity > MAX_HUMIDITY) {
      humidity = MAX_HUMIDITY;
    } else if (humidity < MIN_HUMIDITY) {
      humidity = MIN_HUMIDITY;
    }

    // printing updated weather information
    printf("\nDay %d:\n", i);
    printf("Temperature: %d\n", current_temp);
    printf("Chance of rain: %d%%, Chance of snow: %d%%\n", rain_chance, snow_chance);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Humidity: %d%%\n", humidity);
  }

  return 0;
}