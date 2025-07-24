//FormAI DATASET v1.0 Category: Temperature monitor ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>

#define LOW_TEMP_THRESHOLD 0
#define HIGH_TEMP_THRESHOLD 100

int main() {
  int temperature;
  int i;
  scanf("%d", &temperature);

  if(temperature < LOW_TEMP_THRESHOLD || temperature > HIGH_TEMP_THRESHOLD) {
    printf("Error: Temperature out of range.\n");
    exit(1);
  }

  printf("Temperature: %d\n", temperature);

  // Display temperature as a bar chart
  printf("Temperature as a bar chart:\n");
  for(i = 0; i < temperature/5; i++) {
    printf("|");
  }
  printf("\n");

  // Display temperature in Celsius and Fahrenheit
  printf("Temperature in Celsius: %d\n", temperature);
  printf("Temperature in Fahrenheit: %d\n", temperature*9/5 + 32);

  return 0;
}