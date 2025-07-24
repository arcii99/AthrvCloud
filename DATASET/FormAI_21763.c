//FormAI DATASET v1.0 Category: Smart home automation ; Style: innovative
#include <stdio.h>
#include <time.h>

int main() {
  // Define the current time
  time_t now = time(NULL);

  // Declare variables for the current hour, minute, and second
  struct tm *t = localtime(&now); 
  int hour = t->tm_hour; 
  int min = t->tm_min;
  int sec = t->tm_sec;

  // Declare variables for the temperature and light level
  float temp = 72.5;
  int light = 50;

  // Print out the current time
  printf("The current time is %02d:%02d:%02d.\n", hour, min, sec);
  
  // If it's nighttime, turn on the lights
  if (hour >= 20 || hour < 6) {
    printf("It's nighttime, turning on the lights.\n");
    light = 100;
  }
  // Else, turn off the lights
  else {
    printf("It's daytime, turning off the lights.\n");
    light = 0;
  }

  // If the temperature is too high, turn on the AC
  if (temp > 75) {
    printf("The temperature is too high, turning on the AC.\n");
  }
  // If the temperature is too low, turn on the heater
  else if (temp < 60) {
    printf("The temperature is too low, turning on the heater.\n");
  }
  // Else, turn off the AC and heater
  else {
    printf("The temperature is just right, turning off the AC and heater.\n");
  }

  // Print out the current light level and temperature
  printf("The light level is %d%% and the temperature is %.1f degrees F.\n", light, temp);

  return 0;
}