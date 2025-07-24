//FormAI DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h> // included for printf/scanf functions

int main(void) { // main function starts
  float temp_celsius, temp_fahrenheit; // creating variables to store temperature values

  printf("Enter temperature in Celsius: "); // prompting user to input temperature in Celsius
  scanf("%f", &temp_celsius); // storing user input in temp_celsius variable

  temp_fahrenheit = (temp_celsius * 9 / 5) + 32; // converting Celsius to Fahrenheit

  printf("%.2fC is equivalent to %.2fF\n", temp_celsius, temp_fahrenheit); // displaying converted temperature in Fahrenheit

  return 0; // returning 0 to indicate successful execution of program
} // main function ends