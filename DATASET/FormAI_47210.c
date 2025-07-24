//FormAI DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("\n");
  int choice;
  float temp, converted_temp;
  printf(" Welcome to the Temperature Converter!\n");
  printf("==========================================\n");
  printf("\n");
  printf("Please choose an option below. \n\n1. Convert Celsius to Fahrenheit\n2. Convert Fahrenheit to Celsius\n\nYour choice: ");
  scanf("%d", &choice); // get user choice

  if (choice == 1) // Celsius to Fahrenheit conversion
  {
    printf("\nEnter temperature in Celsius: ");
    scanf("%f", &temp);
    converted_temp = (temp * 1.8) + 32; // formula for Celsius to Fahrenheit conversion
    printf("\n%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temp, converted_temp);
  }
  else if (choice == 2) // Fahrenheit to Celsius conversion
  {
    printf("\nEnter temperature in Fahrenheit: ");
    scanf("%f", &temp);
    converted_temp = (temp - 32) * 0.5556; // formula for Fahrenheit to Celsius conversion
    printf("\n%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temp, converted_temp);
  }
  else // invalid choice
  {
    printf("\nInvalid choice! Please choose 1 or 2.\n");
  }
  
  printf("\nThank you for using the Temperature Converter!\n");
  
  return 0;
}