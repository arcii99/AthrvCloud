//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>

int main() {
  int option;
  float temp, result;
  
  printf("Welcome to the Temperature Converter!\n\n");
  printf("Please choose an option:\n");
  printf("1. Convert from Celsius to Fahrenheit\n");
  printf("2. Convert from Fahrenheit to Celsius\n");
  scanf("%d", &option);
  
  switch(option) {
    case 1:
      printf("\nEnter the temperature in Celsius: ");
      scanf("%f", &temp);
      result = (temp * 9/5) + 32;
      printf("%.2f°C is equal to %.2f°F\n", temp, result);
      break;

    case 2:
      printf("\nEnter the temperature in Fahrenheit: ");
      scanf("%f", &temp);
      result = (temp - 32) * 5/9;
      printf("%.2f°F is equal to %.2f°C\n", temp, result);
      break;

    default:
      printf("\nInvalid option! Please choose either 1 or 2.\n");
      break;
  }
  
  printf("\nThank you for using the Temperature Converter!\n");
  return 0;
}