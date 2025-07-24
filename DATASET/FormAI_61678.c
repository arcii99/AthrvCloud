//FormAI DATASET v1.0 Category: Temperature Converter ; Style: complex
#include<stdio.h>

int main() {
  float temp, celsius, fahrenheit;
  char choice;

  printf("Enter 'C' to convert Celcius to Fahrenheit or 'F' to convert Fahrenheit to Celcius: ");
  scanf("%c", &choice);

  if(choice == 'C' || choice == 'c') {
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
  } 
  else if(choice == 'F' || choice == 'f') {
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5/9;

    printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
  } 
  else {
    printf("Invalid Input\n");
  }

  return 0;
}