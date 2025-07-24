//FormAI DATASET v1.0 Category: Smart home automation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Smart Home Automation System!\n");
  int temperature = 25;
  int lighting = 50;
  int humidity = 60;
  int motion = 0;
  int presence = 0;

  printf("\nChecking the environmental sensors... \n");
  printf("Current temperature is %d°C.\n", temperature);
  printf("Current lighting is %d%%.\n", lighting);
  printf("Current humidity is %d%%.\n", humidity);
  printf("Current motion sensor reading is %d.\n", motion);
  printf("Current presence sensor reading is %d.\n", presence);

  if (temperature > 30) {
    printf("\nIt's too hot! Turning on the air conditioner...\n");
    // Code to turn on the air conditioner
  }
  else if (temperature < 20) {
    printf("\nIt's too cold! Turning on the heater...\n");
    // Code to turn on the heater
  }
  else {
    printf("\nTemperature is just right.\n");
    // Do nothing
  }

  if (humidity > 70) {
    printf("It's too humid! Turning on the dehumidifier...\n");
    // Code to turn on the dehumidifier
  }
  else if (humidity < 30) {
    printf("It's too dry! Turning on the humidifier...\n");
    // Code to turn on the humidifier
  }
  else {
    printf("Humidity is just right.\n");
    // Do nothing
  }

  if (lighting < 10 || motion == 1 || presence == 1) {
    printf("It's dark or there's motion or presence detected. Turning on the lights...\n");
    // Code to turn on the lights
  }
  else {
    printf("Lighting is sufficient.\n");
    // Do nothing
  }

  printf("\nSmart Home Automation System tasks completed. Goodbye!");

  return 0;
}