//FormAI DATASET v1.0 Category: Temperature Converter ; Style: beginner-friendly
#include <stdio.h>

int main() {
  char choice;
  float temperature;

  printf("Enter the temperature: ");
  scanf("%f", &temperature);

  printf("Would you like to convert to Celsius or Fahrenheit? (C/F) ");
  scanf(" %c", &choice);

  if (choice == 'C' || choice == 'c') {
    float convertedTemp = (temperature - 32) * 5 / 9;
    printf("%.2fF is %.2fC\n", temperature, convertedTemp);
  }
  else if (choice == 'F' || choice == 'f') {
    float convertedTemp = (temperature * 9 / 5) + 32;
    printf("%.2fC is %.2fF\n", temperature, convertedTemp);
  }
  else {
    printf("Invalid choice\n");
  }

  return 0;
}