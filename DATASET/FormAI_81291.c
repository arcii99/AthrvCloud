//FormAI DATASET v1.0 Category: Weather simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 50 // in Celsius
#define MIN_TEMPERATURE -30 // in Celsius
#define MAX_HUMIDITY 100 // in percentage
#define MIN_HUMIDITY 0 // in percentage

// Function to generate a random number within a given range
int randomNumber(int min, int max) {
  return min + rand() % (max - min + 1);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Declare variables to hold temperature and humidity
  int temperature, humidity;

  // Initialize the temperature and humidity to random values
  temperature = randomNumber(MIN_TEMPERATURE, MAX_TEMPERATURE);
  humidity = randomNumber(MIN_HUMIDITY, MAX_HUMIDITY);

  // Print the initial weather conditions
  printf("Initial weather conditions:\n");
  printf("Temperature: %d °C\n", temperature);
  printf("Humidity: %d %%\n", humidity);

  // Create a loop to simulate weather changes over time
  for(int i=0; i<10; i++) {
    // Randomly change the temperature and humidity by a certain amount
    int temperatureChange = randomNumber(-5, 5);
    int humidityChange = randomNumber(-10, 10);
    temperature += temperatureChange;
    humidity += humidityChange;

    // Check if the temperature and humidity have gone outside of the safe range
    if (temperature > MAX_TEMPERATURE) {
      temperature = MAX_TEMPERATURE;
    } else if (temperature < MIN_TEMPERATURE) {
      temperature = MIN_TEMPERATURE;
    }
    if (humidity > MAX_HUMIDITY) {
      humidity = MAX_HUMIDITY;
    } else if (humidity < MIN_HUMIDITY) {
      humidity = MIN_HUMIDITY;
    }

    // Print the weather conditions for this iteration
    printf("\nAfter %d hour(s):\n", i+1);
    printf("Temperature: %d °C\n", temperature);
    printf("Humidity: %d %%\n", humidity);

    // Sleep for 1 second to simulate the passing of time
    sleep(1);
  }

  return 0;
}