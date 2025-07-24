//FormAI DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>

int main() {
  char input_type = 'C'; // Fahrenheit by default
  float temp = 0.0;
  float converted_temp = 0.0;

  printf("Welcome to Temperature Converter!\n");
  printf("----------------------------------\n");

  // Prompt user for input temperature and type
  printf("Please enter a temperature to convert: ");
  scanf("%f", &temp);
  printf("Is this temperature in Celsius or Fahrenheit? (C/F): ");
  scanf(" %c", &input_type);

  // Convert the temperature
  if (input_type == 'F') {
    converted_temp = (temp - 32.0) * 5.0 / 9.0;
    printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temp, converted_temp);
  }
  else if (input_type == 'C') {
    converted_temp = temp * 9.0 / 5.0 + 32.0;
    printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temp, converted_temp);
  }
  else {
    printf("Invalid input type. Please enter either C or F.\n");
  }

  return 0;
}