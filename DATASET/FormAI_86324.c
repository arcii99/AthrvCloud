//FormAI DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature, humidity, pressure;
  srand(time(NULL));
  
  printf("Simulating weather conditions...\n");

  for (int i = 0; i < 24; i++) {
    temperature = rand() % 30 + (-10);
    humidity = rand() % 100;
    pressure = rand() % 1000 + 900;

    printf("Hour %d: Temperature: %dC, Humidity: %d%%, Pressure: %dhPa\n", i+1, temperature, humidity, pressure);
    
    if (temperature > 25 && humidity > 70) {
      printf("Warning: High temperature and humidity\n");
    }
    else if (temperature < 0) {
      printf("Warning: Freezing temperature\n");
    }
    else if (pressure < 950 || pressure > 1050) {
      printf("Warning: Unstable pressure\n");
    }
    else {
      printf("Weather conditions are normal\n");
    }
  }
  
  return 0;
}