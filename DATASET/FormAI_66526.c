//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include<stdio.h>

//Function to convert Fahrenheit to Celsius
float FahrenheitToCelsius(float);
//Function to convert Celsius to Fahrenheit
float CelsiusToFahrenheit(float);

int main()
{
  printf("Welcome to the Unit Converter!\n");
  printf("Please enter the unit you want to convert:\n");
  printf("Type 1 for Fahrenheit to Celsius conversion or type 2 for Celsius to Fahrenheit conversion:\n");

  int choice;
  float temperature;

  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("Enter temperature in Fahrenheit:\n");
      scanf("%f", &temperature);
      printf("%.2f Fahrenheit is equal to %.2f Celsius.", temperature, FahrenheitToCelsius(temperature));
      break;

    case 2:
      printf("Enter temperature in Celsius:\n");
      scanf("%f", &temperature);
      printf("%.2f Celsius is equal to %.2f Fahrenheit.", temperature, CelsiusToFahrenheit(temperature));
      break;

    default:
      printf("Invalid choice. Please try again.");
  }

  printf("\nThank you for using the Unit Converter!");
  return 0;
}

float FahrenheitToCelsius(float fahrenheit)
{
  return ((fahrenheit - 32) * 5 / 9);
}

float CelsiusToFahrenheit(float celsius)
{
  return ((celsius * 9 / 5) + 32);
}