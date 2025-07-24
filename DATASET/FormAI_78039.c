//FormAI DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>

int main() {
  int choice;
  float temperature;
  printf("Welcome to Medieval Temperature Converter!\n");
  printf("Please choose an option:\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  
  if (choice == 1) {
    printf("Enter temperature in Celsius: ");
    scanf("%f", &temperature);
    float fahrenheit = (temperature * 9/5) + 32;
    printf("%.2f Celsius is equivalent to %.2f Fahrenheit. May the fire of the dragon warm your bones!\n", temperature, fahrenheit);
  }
  else if (choice == 2) {
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &temperature);
    float celsius = (temperature - 32) * 5/9;
    printf("%.2f Fahrenheit is equivalent to %.2f Celsius. May the frost of the tundra chill your soul!\n", temperature, celsius);
  }
  else {
    printf("Invalid choice. Please choose between 1 and 2. May the spirits guide you!\n");
  }
  
  return 0;
}