//FormAI DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>

int main() {

  int choice;
  float temp;
  float result;

  printf("Welcome to Temperature Unit Converter\n");
  printf("Please select an option to proceed:\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  scanf("%d", &choice);

  if(choice == 1) {
    printf("Please enter the temperature in Celsius: ");
    scanf("%f", &temp);
    result = (temp * 9/5) + 32;
    printf("%.2f deg Celsius is equal to %.2f deg Fahrenheit\n", temp, result);
  } else if(choice == 2) {
    printf("Please enter the temperature in Fahrenheit: ");
    scanf("%f", &temp);
    result = (temp - 32) * 5/9;
    printf("%.2f deg Fahrenheit is equal to %.2f deg Celsius\n", temp, result);
  } else {
    printf("Invalid selection. Please select 1 or 2.\n");
  }

  return 0;
}