//FormAI DATASET v1.0 Category: Smart home automation ; Style: all-encompassing
#include <stdio.h>

int main() {
  // Initialize variables
  int temperature = 24; // degrees Celsius
  int humidity = 40; // percent
  int lightsOn = 0; // 0 = off, 1 = on

  // Check temperature and humidity levels
  if (temperature > 25) {
    printf("Temperature is too high, turning on air conditioner...\n");
    // code to turn on air conditioner
  }
  if (humidity < 30) {
    printf("Humidity is too low, turning on humidifier...\n");
    // code to turn on humidifier
  }

  // Check if lights need to be turned on
  if (!lightsOn && (temperature < 18 || temperature > 21)) {
    printf("It's too dark, turning on lights...\n");
    // code to turn on lights
    lightsOn = 1;
  }

  // Wait for user input to turn off lights
  if (lightsOn) {
    char userInput;
    printf("Would you like to turn off lights? (Y/N)\n");
    scanf(" %c", &userInput);
    if (userInput == 'Y' || userInput == 'y') {
      printf("Turning off lights...\n");
      // code to turn off lights
      lightsOn = 0;
    }
  }

  return 0;
}