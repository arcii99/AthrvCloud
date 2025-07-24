//FormAI DATASET v1.0 Category: Weather simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random temperature */
double generateTemperature() {
  return ((double) rand() / RAND_MAX) * 30;
}

/* Function to calculate the average temperature */
double calculateAverageTemperature(double temperatures[], int numTemperatures) {
  double sum = 0;
  for (int i = 0; i < numTemperatures; i++) {
    sum += temperatures[i];
  }
  return sum / numTemperatures;
}

/* Function to calculate the standard deviation of the temperatures */
double calculateStandardDeviation(double temperatures[], int numTemperatures, double averageTemperature) {
  double sum = 0;
  for (int i = 0; i < numTemperatures; i++) {
    sum += (temperatures[i] - averageTemperature) * (temperatures[i] - averageTemperature);
  }
  return sqrt(sum / numTemperatures);
}

int main() {
  int numDays = 7; // number of simulated days
  int numHours = 24; // number of simulated hours per day
  double temperatures[numDays][numHours]; // array to store the simulated temperatures

  srand(time(NULL)); // initialize random number generator

  printf("Simulating weather...\n");

  // loop through the days and hours to simulate the weather
  for (int day = 0; day < numDays; day++) {
    for (int hour = 0; hour < numHours; hour++) {
      temperatures[day][hour] = generateTemperature();
    }
  }

  // print the temperatures for each day and hour
  for (int day = 0; day < numDays; day++) {
    printf("Temperatures for day %d:\n", day + 1);
    for (int hour = 0; hour < numHours; hour++) {
      printf("Hour %d: %.1f°C\n", hour, temperatures[day][hour]);
    }
    double averageTemperature = calculateAverageTemperature(temperatures[day], numHours);
    double standardDeviation = calculateStandardDeviation(temperatures[day], numHours, averageTemperature);
    printf("Daily average: %.1f°C\n", averageTemperature);
    printf("Daily standard deviation: %.2f°C\n", standardDeviation);
  }

  return 0;
}