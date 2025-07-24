//FormAI DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

// Function prototypes
void printArray(int arr[], int size);
void simulateWeather(int arr[], int size);

int main()
{
  // Seed the random number generator
  srand(time(NULL));

  // Create an array to hold the simulated weather data
  int weather[SIZE];

  // Simulate the weather for the month
  simulateWeather(weather, SIZE);

  // Print the weather data
  printf("Simulated Weather Data\n");
  printf("======================\n");
  printArray(weather, SIZE);

  return 0;
}

void simulateWeather(int arr[], int size)
{
  int i, max, min, range;

  // Set the initial min and max values
  max = 100;
  min = 0;

  // Calculate the range of possible temperature variations
  range = (max - min) / 4;

  // Simulate the weather for each day of the month
  for (i = 0; i < size; i++)
  {
    // Calculate a random temperature variation
    int variation = rand() % (range + 1);

    // Calculate the temperature for the day
    int temperature = min + ((max - min) / 2) + variation - range;

    // Store the temperature in the array
    arr[i] = temperature;
  }
}

void printArray(int arr[], int size)
{
  int i;

  for (i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");
}