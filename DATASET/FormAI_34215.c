//FormAI DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define TEMP_RANGE 20 // temperature range in degrees Celsius
#define TEMP_OFFSET 10 // temperature offset in degrees Celsius

// City struct definition
typedef struct City {
  char *name;
  double longitude;
  double latitude;
  double temperature;
  time_t lastUpdated;
} City;

// Function prototypes
void updateTemperature(City *cities, int numCities);
void printCityInfo(City city);
void printCities(City *cities, int numCities);

int main() {
  // Create cities
  City cities[NUM_CITIES] = {
    {"New York", -74.0060, 40.7128},
    {"Tokyo", 139.6917, 35.6895},
    {"London", -0.1278, 51.5074},
    {"Paris", 2.3522, 48.8566},
    {"Sydney", 151.2093, -33.8688}
  };

  // Seed random number generator
  srand(time(NULL));

  // Update temperatures and print city information
  updateTemperature(cities, NUM_CITIES);
  printCities(cities, NUM_CITIES);

  return 0;
}

/**
 * Updates the temperature of each city in the given array.
 */
void updateTemperature(City *cities, int numCities) {
  for (int i = 0; i < numCities; i++) {
    // Generate random temperature within range
    double temp = (double) rand() / RAND_MAX * TEMP_RANGE + TEMP_OFFSET;

    // Update city temperature and last updated time
    cities[i].temperature = temp;
    time(&cities[i].lastUpdated);
  }
}

/**
 * Prints information about the given city.
 */
void printCityInfo(City city) {
  printf("%s:\n", city.name);
  printf("Longitude: %f\n", city.longitude);
  printf("Latitude: %f\n", city.latitude);
  printf("Temperature: %.2f Celsius\n", city.temperature);
  printf("Last updated: %s\n\n", ctime(&city.lastUpdated));
}

/**
 * Prints information about each city in the given array.
 */
void printCities(City *cities, int numCities) {
  for (int i = 0; i < numCities; i++) {
    printCityInfo(cities[i]);
  }
}