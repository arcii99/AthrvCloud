//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surrealist
#include <stdio.h>

int main() {
  float temperature = 0;
  int count = 0;

  printf("Welcome to the inter-dimensional temperature monitor.\n");
  printf("Please input the temperature in Celsius:\n");

  while (count < 5) {
    scanf("%f", &temperature);

    if (temperature >= -273.15) {
      printf("The temperature is %f degrees Celsius, which is %f degrees Kelvin.\n", temperature, temperature + 273.15);

      if (temperature >= 35) {
        printf("Warning: Temperature is too hot for regular humans to handle. Please take necessary precautions.\n");
      } else if (temperature <= -40) {
        printf("Warning: Temperature is too cold for regular humans to handle. Please take necessary precautions.\n");
      }

      count++;
    } else {
      printf("Invalid temperature. Please input a temperature higher than absolute zero (-273.15 C)\n");
    }
  }

  printf("Thank you for using the inter-dimensional temperature monitor. Please come back again.\n");

  return 0;
}