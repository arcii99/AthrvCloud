//FormAI DATASET v1.0 Category: Temperature monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float temperature;
  printf("Enter the current temperature in Celsius: ");
  scanf("%f", &temperature);
  if (temperature < -50 || temperature > 150) {
    printf("Invalid temperature input. Please try again.\n");
    return 1;
  }

  printf("The current temperature in Celsius is: %.2f\n", temperature);

  //convert to Fahrenheit
  float fahrenheit = (temperature * 9/5) + 32;
  printf("The current temperature in Fahrenheit is: %.2f\n", fahrenheit);

  //check for extreme temperatures
  if (fahrenheit < 32) {
    printf("It's freezing outside!\n");
  }
  else if (fahrenheit > 90) {
    printf("Stay cool, it's hot out there!\n");
  }
  else {
    printf("Looks like a comfortable temperature.\n");
  }
  
  return 0;
}