//FormAI DATASET v1.0 Category: Temperature monitor ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function to generate random temperature values */
float generateRandomTemperature() {
  float minTemp = -10.0;
  float maxTemp = 40.0;
  float randomTemp = (float)rand() / (float)RAND_MAX;
  float tempRange = maxTemp - minTemp;
  return (randomTemp * tempRange) + minTemp;
}

/* Function to check if the temperature is within the safe limit */
int isTemperatureSafe(float temperature) {
  if (temperature < 0.0 || temperature > 37.0) {
    return 0;
  }
  return 1;
}

/* Main function to monitor the temperature */
int main() {
  srand(time(NULL)); // Seed the random function with the current time
  printf("\nWelcome to the Temperature Monitor!\n");

  int timeInterval = 10; // Time interval between temperature readings

  printf("\nTemperature monitor initiated. I will check the temperature every %d seconds.\n", timeInterval);

  /* Infinite loop to monitor the temperature */
  while (1) {
    float currentTemperature = generateRandomTemperature(); // Get the current temperature
    printf("\nCurrent temperature: %.2f C", currentTemperature);
    if (isTemperatureSafe(currentTemperature)) {
      printf("\nTemperature is safe. Enjoy your day!\n");
    } else {
      printf("\nTemperature is not safe. Please take necessary precautions!\n");
    }

    printf("-------------------------------------------");

    /* Wait for the specified time interval */
    printf("\nWaiting for %d seconds...\n", timeInterval);
    sleep(timeInterval);
  }

  return 0;
}