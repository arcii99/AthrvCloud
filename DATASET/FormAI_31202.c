//FormAI DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

int main() {
  int choice;
  float value, result;
  printf("Welcome to the unit converter!\n");
  printf("==============================\n");
  printf("Please choose the conversion you want to perform:\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Kilometers to Miles\n");
  printf("3. Liters to Gallons\n");
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      printf("Enter a temperature in Celsius: ");
      scanf("%f", &value);
      result = (value * 9/5) + 32;
      printf("%.2f Celsius is equal to %.2f Fahrenheit", value, result);
      break;
      
    case 2:
      printf("Enter a distance in kilometers: ");
      scanf("%f", &value);
      result = value * 0.621371;
      printf("%.2f kilometers is equal to %.2f miles", value, result);
      break;
      
    case 3:
      printf("Enter a volume in liters: ");
      scanf("%f", &value);
      result = value * 0.264172;
      printf("%.2f liters is equal to %.2f gallons", value, result);
      break;
      
    default:
      printf("Invalid choice!");
      break;
  }
  
  return 0;
}