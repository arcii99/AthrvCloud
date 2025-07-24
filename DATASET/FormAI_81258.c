//FormAI DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Define the maximum and minimum temperature values
#define MAX_TEMP 100
#define MIN_TEMP 0

int main() {
  // Initialize variables
  float temperature;
  srand(time(0)); // Seed the random number generator
  
  while(1) { // Keep monitoring the temperature indefinitely
    // Generate a random temperature value between MIN_TEMP and MAX_TEMP
    temperature = (float)(rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP);
    
    // Print the temperature value on the screen
    printf("Current temperature: %.2f°C\n", temperature);
    
    // If the temperature value is below 0 or above 100, send an alert
    if(temperature < MIN_TEMP || temperature > MAX_TEMP) {
      printf("ALERT: Temperature out of range!\n");
    }
    
    // Wait for 2 seconds before measuring the temperature again
    sleep(2);
  }
  
  return 0;
}