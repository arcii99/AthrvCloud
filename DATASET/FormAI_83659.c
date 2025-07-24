//FormAI DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float readTemperature() {
  // Code here to read temperature from sensor
  srand(time(NULL)); // Seed random number generator
  return (float)(rand() % 100) / 2.0; // Generate random value between 0 and 50
}

int main() {
   float celsius = readTemperature();
   float fahrenheit = (9.0 / 5.0) * celsius + 32;

   printf("Temperature in Celsius: %.2f\n", celsius);
   printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);

   if (celsius > 37.5) {
      printf("WARNING: High temperature detected! Please seek medical attention.\n");
   }

   return 0;
}