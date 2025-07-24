//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

/* function to generate a random temperature reading */
float generateTemp() {
  float temperature = (rand() / (float)RAND_MAX) * 100.0;
  return temperature;
}

/* function to convert temperature from Celsius to Fahrenheit */
float toFahrenheit(float temperature_celsius) {
  float temperature_fahrenheit = (temperature_celsius * 9.0/5.0) + 32.0;
  return temperature_fahrenheit;
}

int main() {
  float temperature_celsius, temperature_fahrenheit;
  int counter = 0;

  while (1) {
    counter++;
    temperature_celsius = generateTemp();
    temperature_fahrenheit = toFahrenheit(temperature_celsius);

    printf("Temperature Reading #%d:\n", counter);
    printf("   Celsius: %.2f\n", temperature_celsius);
    printf("   Fahrenheit: %.2f\n\n", temperature_fahrenheit);

    /* sleep for 1 second */
    sleep(1);
  }

  return 0;
}