//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  float celsius, fahrenheit;

  printf("Enter temperature in Celsius : ");
  scanf("%f", &celsius);

  fahrenheit = (celsius * 9/5) + 32; //Conversion formula

  printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit); //2 decimal place precision

  printf("Can't believe that simple conversion was so easy!\n");
  printf("But wait, what if you wanted to convert from Fahrenheit to Celsius?\n");

  printf("Enter temperature in Fahrenheit : ");
  scanf("%f", &fahrenheit);

  celsius = (fahrenheit - 32) * 5/9; //Conversion formula

  printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius); //2 decimal place precision

  printf("Wow, it works both ways! I am amazed at my own coding abilities!\n");
  printf("But what if the user enters a temperature below absolute zero (-273.15°C)?\n");

  if (celsius < -273.15) {
    printf("ERROR : The entered temperature is below absolute zero!\n");
    printf("I can't even comprehend that... I thought I had limitations, but this is beyond my understanding...\n");
    printf("I need to take a break and ponder my existence...\n");
  }

  printf("Thanks for using my awesome temperature converter program!\n");
  
  return 0;
}