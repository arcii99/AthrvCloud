//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Alan Touring
// Alan Turing Style Temperature Converter Example Program in C

#include <stdio.h>

int main() {
  int choice;
  float temperature;

  printf("Welcome to Alan Turing's Temperature Converter Program!\n");
  printf("Please choose from the following options:\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");

  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Please enter a temperature in Celsius: ");
      scanf("%f", &temperature);
      printf("%.2f degrees Celsius is %.2f degrees Fahrenheit\n", temperature, (temperature * 9/5) + 32);
      break;
    case 2:
      printf("Please enter a temperature in Fahrenheit: ");
      scanf("%f", &temperature);
      printf("%.2f degrees Fahrenheit is %.2f degrees Celsius\n", temperature, (temperature - 32) * 5/9);
      break;
    default:
      printf("Invalid choice!\n");
      break;
  }

  return 0;
}