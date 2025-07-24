//FormAI DATASET v1.0 Category: Temperature monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
  float temperature = 0.0;

  while(1) { // Run indefinitely
    printf("Enter current temperature (in Celsius): ");
    scanf("%f", &temperature);

    if(temperature < 0) {
      printf("Warning: Temperature is below freezing point!\n");
    } else if (temperature > 100) {
      printf("Warning: Temperature is above boiling point!\n");
    } else {
      printf("Temperature is within normal range.\n");
    }
  }

  return 0;
}