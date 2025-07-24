//FormAI DATASET v1.0 Category: Temperature monitor ; Style: all-encompassing
#include <stdio.h>

int main() {
  float temperature;
  printf("Enter the current temperature in Celsius: ");
  scanf("%f", &temperature);

  if (temperature < -273.15) {
    printf("Invalid temperature! Temperature can't be below absolute zero.\n");
    return 1;
  }

  printf("Temperature entered: %.2fC\n", temperature);
  
  if (temperature <= 0) {
    printf("Warning: Temperature is below freezing point.\n");
  }
  else if (temperature >= 100) {
    printf("Warning: Temperature is above boiling point.\n");
  }
  else {
    printf("Normal temperature range.\n");
  }

  return 0;
}