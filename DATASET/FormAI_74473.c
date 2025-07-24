//FormAI DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
  int temperature;
  srand(time(0)); // for randomization

  while (1) {
    temperature = rand() % 100; // simulate temperature readings
    printf("Current temperature: %d°C\n", temperature);

    if (temperature > 80) {
      printf("WARNING: Temperature is too high! Cooling down...\n");
      // code to cool down the system goes here
    } else if (temperature < 70) {
      printf("WARNING: Temperature is too low! Heating up...\n");
      // code to heat up the system goes here
    }

    sleep(5); // wait for 5 seconds before taking next reading
  }

  return 0;
}