//FormAI DATASET v1.0 Category: Weather simulation ; Style: futuristic
// This is a weather simulation program in the year 2050
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random temperature
float generateTemperature() {
  return (float)(rand() % 101);
}

// Function to generate random atmospheric pressure
float generatePressure() {
  return (float)(rand() % 101);
}

// Function to generate random humidity
float generateHumidity() {
  return (float)(rand() % 101);
}

int main() {
  srand(time(NULL)); // Seed for random values
  int time = 0; // Variable to keep track of time
  float temperature = 25.0, pressure = 100.0, humidity = 50.0; // Initial weather conditions
  printf("Welcome to the Weather Simulation Program\n");
  printf("Press Ctrl+C to exit the program\n");
  while(1) {
    printf("\n\nTime: %d\nTemperature: %.1f°C\nPressure: %.1f atm\nHumidity: %.1f%%\n", time, temperature, pressure, humidity);
    temperature += (generateTemperature() - 50.0) / 10.0;
    pressure += (generatePressure() - 50.0) / 100.0;
    humidity += (generateHumidity() - 50.0) / 20.0;
    time++;
    sleep(1); // Wait for one second
  }
  return 0;
}