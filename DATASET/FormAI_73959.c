//FormAI DATASET v1.0 Category: Temperature monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Temperature monitor function */
void temperatureMonitor(void) {
  srand(time(NULL)); // Initialize random seed

  int temp;
  bool isSafe = true;

  printf("Starting temperature monitoring...\n");

  // Continuously monitor temperature
  while (isSafe) {
    temp = rand() % 100; // Generate random temperature between 0-99 degrees Celsius
    printf("Current temperature: %d degrees Celsius\n", temp);

    // Check if temperature is too hot (above 80 degrees Celsius)
    if (temp > 80) {
      printf("The temperature is too hot! System shutting down.\n");
      isSafe = false; // Set flag to false to stop monitoring
    }
    
    // Check if temperature is too cold (below 0 degrees Celsius)
    else if (temp < 0) {
      printf("The temperature is too cold! System shutting down.\n");
      isSafe = false; // Set flag to false to stop monitoring
    }

    // Wait for 1 second before checking temperature again
    sleep(1);
  }

  printf("Temperature monitoring stopped.\n");
}

int main() {
  temperatureMonitor();
  return 0;
}