//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define maximum and minimum temperature
#define MAX_TEMP 60
#define MIN_TEMP -40

int main() {
  // Generates the Seed for random number
  srand(time(NULL));

  // Set initial temperature to a random value between -40 and 60
  int temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;

  // Main loop
  while (1) {
    // Clear the screen
    system("clear");

    // Display the current temperature
    printf("CYBERTEMP MONITOR 1.0\n");
    printf("_______________________________\n");
    printf("  CURRENT TEMPERATURE: %d°C\n", temperature);

    // Check if temperature is too high
    if (temperature >= 50) {
      printf("\nWARNING: Temperature is too high. Seek shelter immediately!\n");
    }

    // Check if temperature is too low
    if (temperature <= -30) {
      printf("\nWARNING: Temperature is too low. Seek shelter immediately!\n");
    }

    // Randomly increase or decrease temperature by 1 to 5 degrees
    int increase = rand() % 2;
    int change = rand() % 4 + 1;
    if (increase) {
      temperature += change;
    } else {
      temperature -= change;
    }

    // Pause for a moment
    usleep(500000);
  }

  return 0;
}