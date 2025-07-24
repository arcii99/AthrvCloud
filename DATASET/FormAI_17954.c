//FormAI DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Seed the random generator
  srand(time(0));

  // Set the initial temperature and humidity
  float temperature = 20.0;
  float humidity = 50.0;

  // Set the initial wind direction and speed
  char* wind_directions[] = {"north", "south", "east", "west"};
  float wind_speeds[] = {0.1, 0.2, 0.3, 0.4, 0.5};
  int num_wind_directions = sizeof(wind_directions) / sizeof(wind_directions[0]);
  int num_wind_speeds = sizeof(wind_speeds) / sizeof(wind_speeds[0]);
  int wind_direction_index = rand() % num_wind_directions;
  float wind_speed = wind_speeds[rand() % num_wind_speeds];

  // Set the initial cloud cover
  float cloud_cover = 0.0;

  // Set the simulation parameters
  int num_iterations = 1000;
  int iteration_interval_ms = 1000;

  printf("Starting weather simulation\n");

  for (int i = 0; i < num_iterations; i++) {

    // Print the current weather conditions
    printf("Temperature: %0.1f°C, Humidity: %0.1f%%, Wind: %s %0.1fm/s, Cloud Cover: %0.1f%%\n",
           temperature, humidity, wind_directions[wind_direction_index], wind_speed, cloud_cover);

    // Update the temperature and humidity
    float temperature_change = ((float)rand()/(float)(RAND_MAX)) * 2.0 - 1.0;
    float humidity_change = ((float)rand()/(float)(RAND_MAX)) * 2.0 - 1.0;
    temperature += temperature_change;
    humidity += humidity_change;

    // Update the wind direction and speed
    if (rand() % 2 == 0) {
      wind_direction_index = (wind_direction_index + 1) % num_wind_directions;
    } else {
      wind_direction_index = (wind_direction_index - 1 + num_wind_directions) % num_wind_directions;
    }
    wind_speed *= ((float)rand()/(float)(RAND_MAX)) * 0.2 + 0.9;

    // Update the cloud cover
    float cloud_cover_change = ((float)rand()/(float)(RAND_MAX)) * 2.0 - 1.0;
    cloud_cover += cloud_cover_change;
    if (cloud_cover > 100.0) {
      cloud_cover = 100.0;
    } else if (cloud_cover < 0.0) {
      cloud_cover = 0.0;
    }

    // Wait for the next iteration
    printf("\n");
    sleep(iteration_interval_ms / 1000);
  }

  printf("Weather simulation finished\n");

  return 0;
}