//FormAI DATASET v1.0 Category: Temperature monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_UPPER_LIMIT 100
#define TEMP_LOWER_LIMIT 0
#define TEMP_RANGE (TEMP_UPPER_LIMIT - TEMP_LOWER_LIMIT)

int main() {
  float temp;
  srand(time(NULL)); // Seed the random number generator with time

  for(int i = 0; i < 10; i++) {
    temp = rand() % TEMP_RANGE + TEMP_LOWER_LIMIT; // Generate a random temperature
    printf("Temperature Reading %d: %.2f Celsius\n", i+1, temp);

    // Check if temperature is above the upper limit
    if(temp > TEMP_UPPER_LIMIT) {
      printf("*** WARNING: Temperature too high! ***\n");
    }

    // Check if temperature is below the lower limit
    else if(temp < TEMP_LOWER_LIMIT) {
      printf("*** WARNING: Temperature too low! ***\n");
    }
  }

  return 0;
}