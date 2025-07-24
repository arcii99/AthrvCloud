//FormAI DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>

int main() {
  int option;
  float value, result;

  printf("Retro Unit Converter\n");
  printf("--------------------\n");
  printf("1. Feet to Meters\n");
  printf("2. Pounds to Kilograms\n");
  printf("3. Gallons to Liters\n");
  printf("4. Fahrenheit to Celsius\n");
  printf("Enter your option: ");
  scanf("%d", &option);

  switch(option) {
     case 1:
        printf("Enter feet value: ");
        scanf("%f", &value);
        result = value * 0.3048;
        printf("%.2f feet = %.2f meters \n", value, result);
        break;
     case 2:
        printf("Enter pounds value: ");
        scanf("%f", &value);
        result = value * 0.453592;
        printf("%.2f pounds = %.2f kilograms\n", value, result);
        break;
     case 3:
        printf("Enter gallons value: ");
        scanf("%f", &value);
        result = value * 3.78541;
        printf("%.2f gallons = %.2f liters\n", value, result);
        break;
     case 4:
        printf("Enter Fahrenheit value: ");
        scanf("%f", &value);
        result = (value - 32) / 1.8;
        printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
        break;
     default:
        printf("Invalid option\n");
  }

  return 0;
}