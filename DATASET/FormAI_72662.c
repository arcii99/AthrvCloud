//FormAI DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>

int main(void) {
  int choice;
  float unit;

  printf("Welcome to the Unit Converter Program!\n");
  printf("Please select the type of unit you would like to convert:\n");
  printf("1. Length\n");
  printf("2. Weight\n");
  printf("3. Temperature\n");
  printf("Enter your choice(1-3): ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Please enter the length in centimeters: ");
      scanf("%f", &unit);
      printf("%.2f cm is equivalent to:\n", unit);
      printf("%.2f inches\n", unit / 2.54);
      printf("%.2f feet\n", unit / 30.48);
      printf("%.2f yards\n", unit / 91.44);
      break;

    case 2:
      printf("Please enter the weight in kilograms: ");
      scanf("%f", &unit);
      printf("%.2f kg is equivalent to:\n", unit);
      printf("%.2f ounces\n", unit * 35.274);
      printf("%.2f pounds\n", unit * 2.20462);
      printf("%.2f stones\n", unit / 6.35029);
      break;

    case 3:
      printf("Please enter the temperature in Celsius: ");
      scanf("%f", &unit);
      printf("%.2f°C is equivalent to:\n", unit);
      printf("%.2f°F\n", (unit * 1.8) + 32);
      printf("%.2f Kelvin\n", unit + 273.15);
      break;

    default:
      printf("Invalid choice, please try again.\n");
      break;
  }

  return 0;
}