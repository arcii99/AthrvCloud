//FormAI DATASET v1.0 Category: Unit converter ; Style: shocked
#include<stdio.h> // Importing Input and output header file
  
int main() {

  float celsius, fahrenheit;  // Defining Celsius and Fahrenheit as floats
 
  printf("Enter temperature value in Celsius: ");  // Taking input value
  scanf("%f", &celsius);  // Reading Celsius value

  // Converting Celsius to Fahrenheit using the formula: F = (C x 9/5) + 32
  fahrenheit = (celsius * 9/5) + 32;  // Formula to convert Celsius to Fahrenheit

  printf("%.2f Celsius is equal to %.2f Fahrenheit", celsius, fahrenheit);  // Displaying the result
  
  return 0;  // End of program
}