//FormAI DATASET v1.0 Category: Weather simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random temperature
int generateTemperature() {
  int minValue = -5; // Minimum temperature
  int maxValue = 45; // Maximum temperature
  int range = maxValue - minValue + 1;
  int randomValue = rand() % range;
  return randomValue + minValue;
}

// Function to generate random precipitation
char generatePrecipitation() {
  char precipitations[] = {'S', 'R', 'H', 'F', ' ', ' '}; // Precipitations to be selected randomly
  int randomIndex = rand() % 6;
  return precipitations[randomIndex];
}

// Function to display weather for a given day
void displayWeather(int day, int temperature, char precipitation) {
  printf("Day %d: Temperature %dC, Precipitation %c\n", day, temperature, precipitation);
}

int main() {
  srand(time(0)); // To seed the random number generator with current time
  
  printf("Welcome to the Weather simulation program!\n\n");

  // Generate weather for 7 days
  for(int i = 1; i <= 7; i++) {
    int temperature = generateTemperature();
    char precipitation = generatePrecipitation();

    // Display the weather for the day
    displayWeather(i, temperature, precipitation);
  }

  printf("\nThanks for using the Weather simulation program!\n");

  return 0;
}