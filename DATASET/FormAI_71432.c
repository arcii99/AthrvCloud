//FormAI DATASET v1.0 Category: Weather simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // seed random number generator with current time

  int temperature = 20;
  int humidity = 50;
  int wind_speed = 5;

  printf("Welcome to the Weather Simulation Program!\n");

  while(1) {
    printf("\nCurrent Temperature: %d degrees Celsius\n", temperature);
    printf("Current Humidity: %d percent\n", humidity);
    printf("Current Wind Speed: %d km/h\n\n", wind_speed);

    int temp_change = rand() % 11 - 5; // generate a random change in temperature between -5 and 5 degrees
    temperature += temp_change;

    int hum_change = rand() % 11 - 5; // generate a random change in humidity between -5 and 5 percent
    humidity += hum_change;

    int wind_change = rand() % 11 - 5; // generate a random change in wind speed between -5 and 5 km/h
    wind_speed += wind_change;

    printf("Press any key to update the weather simulation...");
    getchar(); // wait for user input before updating the weather simulation
  }

  return 0;
}