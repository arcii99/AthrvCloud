//FormAI DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // set the random number generator seed to the current time

  float temperature = -40.0; // initialize temperature to minimum possible value
  int targetTemp = rand() % 101; // generate a random target temperature between 0 and 100 degrees Celsius
  float humidity = 0.0; // initialize the humidity to 0%
  int pressure = 800; // set the pressure to a standard value of 800 millibars
  char weather[15]; // create a character array to hold the weather description

  // loop until the current temperature reaches the target temperature
  while (temperature < targetTemp) {
    temperature += 0.5; // increment temperature by 0.5 degrees Celsius each loop
    humidity += 0.1; // increment humidity by 10% each loop
    pressure += rand() % 3; // add a random amount of pressure variation between 0 and 2 millibars each loop

    // determine the weather description based on temperature and humidity
    if (temperature < 0.0) {
      if (humidity < 50.0) {
        strcpy(weather, "Clear and cold");
      } else {
        strcpy(weather, "Snow");
      }
    } else if (temperature < 10.0) {
      if (humidity < 50.0) {
        strcpy(weather, "Partly cloudy");
      } else {
        strcpy(weather, "Light rain or drizzle");
      }
    } else if (temperature < 20.0) {
      if (humidity < 50.0) {
        strcpy(weather, "Sunny");
      } else {
        strcpy(weather, "Humid");
      }
    } else if (temperature < 30.0) {
      if (humidity < 50.0) {
        strcpy(weather, "Hot and dry");
      } else {
        strcpy(weather, "Thunderstorms");
      }
    } else {
      if (humidity < 50.0) {
        strcpy(weather, "Heat wave");
      } else {
        strcpy(weather, "Tropical storm");
      }
    }

    // print out the current weather conditions
    printf("Temperature: %.1f degrees Celsius\n", temperature);
    printf("Humidity: %.0f%%\n", humidity);
    printf("Pressure: %d millibars\n", pressure);
    printf("Weather: %s\n\n", weather);

    // wait for a short period before looping again
    fflush(stdout);
    sleep(1);
  }

  // print out the final target temperature and exit the program
  printf("Target temperature of %d degrees Celsius reached. Simulation complete.", targetTemp);
  return 0;
}