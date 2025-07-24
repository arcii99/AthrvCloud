//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
double getTemperature();
void printStatus(double temp);

int main() {
  // seed the random number generator
  srand(time(NULL));

  // loop forever
  while (1) {
    // get current temperature
    double currentTemp = getTemperature();

    // print status message
    printStatus(currentTemp);

    // wait for 1 second before checking temperature again
    sleep(1);
  }

  return 0;
}

// returns a random temperature between 20 and 30 degrees Celsius
double getTemperature() {
  double temp = (double)rand() / (double)(RAND_MAX) * 10.0 + 20.0;
  return temp;
}

// prints the current temperature and status message
void printStatus(double temp) {
  printf("Temperature: %0.2f degrees Celsius\n", temp);

  if (temp < 22.0) {
    printf("[INFO] Temperature too low.\n");
  } else if (temp > 28.0) {
    printf("[WARNING] Temperature too high!\n");
  } else {
    printf("[OK] Temperature within acceptable range.\n");
  }
}