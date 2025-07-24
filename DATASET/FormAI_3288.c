//FormAI DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed random number generator
  srand(time(0));

  // Print ominous message
  printf("Initializing weather simulation...\n");
  printf("Beware, for the power of the skies is in our hands.\n");
  printf("Will we be benevolent or will we unleash chaos?\n");
  printf("The fate of the world depends on our every decision.\n");

  // Initialize variables for weather conditions
  float temperature = 72.0;
  float humidity = 50.0;
  float pressure = 29.9;
  float windSpeed = 5.0;
  int lightning = 0;
  int hurricanes = 0;

  // Start simulation loop
  int i;
  for (i = 0; i < 365; i++) {
    printf("\nDay %d:\n", i+1);

    // Randomly fluctuate temperature, humidity, pressure, and wind speed
    temperature += (float)(rand() % 11 - 5); // +/- 5 degrees Fahrenheit
    humidity += (float)(rand() % 11 - 5);    // +/- 5%
    pressure += (float)(rand() % 11 - 5) / 10.0; // +/- 0.5 inHg
    windSpeed += (float)(rand() % 11 - 5);  // +/- 5 mph

    // Check for severe weather conditions
    if (temperature > 100 || temperature < 0) {
      printf("ERROR: Temperature out of range!\n");
      exit(1);
    } else if (humidity > 100 || humidity < 0) {
      printf("ERROR: Humidity out of range!\n");
      exit(1);
    } else if (pressure > 30.5 || pressure < 29.0) {
      printf("ALERT: Pressure out of nominal range!\n");
    } else if (windSpeed > 50) {
      printf("WARNING: Wind speed dangerously high!\n");
    }

    // Generate lightning and hurricanes randomly
    if (rand() % 100 < 5) { // 5% chance of lightning
      printf("ALERT: Lightning detected!\n");
      lightning++;
    }
    if (rand() % 100 < 2) { // 2% chance of hurricane
      printf("WARNING: Hurricane forming in the Atlantic!\n");
      hurricanes++;
    }
  }

  // Print final report
  printf("\n\n=====================\nFINAL REPORT:\n");
  printf("Total lightning strikes: %d\n", lightning);
  printf("Total hurricanes: %d\n", hurricanes);

  // Check if we caused any catastrophes
  if (lightning > 100) {
    printf("WARNING: We may have caused a wildfire!\n");
  }
  if (hurricanes > 3) {
    printf("ALERT: We may have caused a major natural disaster!\n");
  }

  printf("\nSimulation complete. The illusions of control are shattered.\n");
  printf("Never forget the responsibility we hold in our hands, for the wrath of nature is a fearsome thing.\n");

  return 0;
}