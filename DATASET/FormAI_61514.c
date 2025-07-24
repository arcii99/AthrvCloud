//FormAI DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>

int main() {
  float temperature = 0.0f;

  printf("Enter temperature in Celsius: ");
  scanf("%f", &temperature);

  if (temperature < -273.15f) {
    printf("Temperature cannot be below absolute zero (−273.15°C)");
  }
  else {
    float fahrenheit = (temperature * 9 / 5) + 32;
    printf("%.2f°C is equivalent to %.2f°F\n", temperature, fahrenheit);

    if (fahrenheit < 32) {
      printf("It's very cold outside!\n");
    }
    else if (fahrenheit < 50) {
      printf("It's a bit chilly outside.\n");
    }
    else if (fahrenheit < 70) {
      printf("It's a nice day outside.\n");
    }
    else if (fahrenheit < 90) {
      printf("It's quite warm outside.\n");
    }
    else {
      printf("It's very hot outside!\n");
    }
  }

  return 0;
}