//FormAI DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>

int main() {
  int option;
  float value, result;

  printf("Welcome to the C Unit Converter!\n");
  printf("Select an option:\n");
  printf("1. Length\n");
  printf("2. Temperature\n");
  printf("3. Volume\n");
  printf("4. Weight\n");
  scanf("%d", &option);
  
  switch(option) {
    case 1:
      printf("Enter a value in meters: ");
      scanf("%f", &value);
      result = value * 3.28084;
      printf("%.2f meters is equal to %.2f feet.\n", value, result);
      break;
    case 2:
      printf("Enter a value in Celsius: ");
      scanf("%f", &value);
      result = (value * 1.8) + 32;
      printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", value, result);
      break;
    case 3:
      printf("Enter a value in liters: ");
      scanf("%f", &value);
      result = value * 0.264172;
      printf("%.2f liters is equal to %.2f gallons.\n", value, result);
      break;
    case 4:
      printf("Enter a value in kilograms: ");
      scanf("%f", &value);
      result = value * 2.20462;
      printf("%.2f kilograms is equal to %.2f pounds.\n", value, result);
      break;
    default:
      printf("Invalid option selected. Please try again.\n");
  }
  
  return 0;
}