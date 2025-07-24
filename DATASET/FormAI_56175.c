//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>

int main() {
  float temperature, convertedTemp;
  int choice;

  printf("Enter temperature: ");
  scanf("%f", &temperature);

  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");

  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      convertedTemp = temperature * 1.8 + 32;
      printf("%.2fC is %.2fF\n", temperature, convertedTemp);
      break;
    case 2:
      convertedTemp = (temperature - 32) / 1.8;
      printf("%.2fF is %.2fC\n", temperature, convertedTemp);
      break;
    default:
      printf("Invalid choice\n");
      break;
  }

  return 0;
}