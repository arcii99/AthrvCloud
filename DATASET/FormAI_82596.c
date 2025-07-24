//FormAI DATASET v1.0 Category: Weather simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to Weather Simulator!\n");

  // Define the variables to store the values for the simulated weather
  float temperature = 0.0;
  float humidity = 0.0;
  float pressure = 0.0;

  // Randomly generate the initial weather conditions using the time as a seed for the random number generator
  srand(time(NULL));
  temperature = ((float)rand()/(float)(RAND_MAX)) * 40 - 20; // generate a value between -20 and 20
  humidity = ((float)rand()/(float)(RAND_MAX)) * 100; // generate a value between 0 and 100
  pressure = ((float)rand()/(float)(RAND_MAX)) * 1000 + 500; // generate a value between 500 and 1500

  // Output the initial weather conditions to the user
  printf("Initial conditions:\nTemperature: %.1f °C\nHumidity: %.1f %%\nPressure: %.1f hPa\n\n", temperature, humidity, pressure);

  // Initialize the variables used to simulate the weather changes
  float deltaT;
  float deltaH;
  float deltaP;

  // Simulate the weather changes for 24 hours, with readings every hour
  for (int hour = 1; hour <= 24; hour++) {
    // Generate the weather changes for this hour
    deltaT = ((float)rand()/(float)(RAND_MAX)) * 2 - 1; // generate a value between -1 and 1
    deltaH = ((float)rand()/(float)(RAND_MAX)) * 10 - 5; // generate a value between -5 and 5
    deltaP = ((float)rand()/(float)(RAND_MAX)) * 20 - 10; // generate a value between -10 and 10

    // Update the weather conditions with the changes for this hour
    temperature += deltaT;
    humidity += deltaH;
    pressure += deltaP;

    // Output the new weather conditions to the user
    printf("Hour %d conditions:\nTemperature: %.1f °C (Δ = %.1f)\nHumidity: %.1f %% (Δ = %.1f)\nPressure: %.1f hPa (Δ = %.1f)\n\n", hour, temperature, deltaT, humidity, deltaH, pressure, deltaP);
  }

  // Output a final message to the user
  printf("Simulation complete.\n");

  return 0;
}