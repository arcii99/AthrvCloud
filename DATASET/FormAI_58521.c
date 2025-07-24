//FormAI DATASET v1.0 Category: Temperature monitor ; Style: relaxed
#include <stdio.h>

// Define some constants to make the code more readable
#define TEMPERATURE_THRESHOLD 70
#define TEMPERATURE_CHECK_INTERVAL 10

int main() {
  int currentTemperature = 0;
  
  // Keep monitoring the temperature indefinitely
  while(1) {
    // Simulate reading the temperature value from some sensor
    currentTemperature = rand() % 100;
    
    // Check if the temperature exceeds the threshold
    if(currentTemperature > TEMPERATURE_THRESHOLD) {
      printf("ALERT: Temperature is above the threshold of %d degrees C. Current temperature is %d degrees C.\n", TEMPERATURE_THRESHOLD, currentTemperature);
    } else {
      printf("Temperature is within normal range. Current temperature is %d degrees C.\n", currentTemperature);
    }
    
    // Wait for some time before checking the temperature again
    sleep(TEMPERATURE_CHECK_INTERVAL);
  }
  
  return 0;
}