//FormAI DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>

int main() {
  float temp = 0;
  int count = 0;
  float totalTemp = 0;
  float averageTemp = 0;

  printf("Enter the number of temperature readings: ");
  scanf("%d", &count);

  if (count <= 0) {
    printf("Invalid input.");
    return 0;
  }

  for (int i = 1; i <= count; i++) {
    printf("Enter temperature reading %d: ", i);
    scanf("%f", &temp);

    if (temp < -273.15) {
      printf("Temperature cannot be below absolute zero.\n");
      i--;
      continue;
    }

    totalTemp += temp;
  }

  averageTemp = totalTemp / count;

  printf("Average temperature is %.2f\n", averageTemp);

  if (averageTemp > 30) {
    printf("Warning: high temperature!\n");
  }

  return 0;
}