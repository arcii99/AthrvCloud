//FormAI DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>

typedef struct {
  bool isLightsOn;
  bool isThermostatEnabled;
  int currentTemperature;
} HomeStatus;

void turnOnLights(HomeStatus* status) {
  printf("Turning on lights...\n");
  status->isLightsOn = true;
}

void turnOffLights(HomeStatus* status) {
  printf("Turning off lights...\n");
  status->isLightsOn = false;
}

void enableThermostat(HomeStatus* status) {
  printf("Enabling thermostat...\n");
  status->isThermostatEnabled = true;
}

void disableThermostat(HomeStatus* status) {
  printf("Disabling thermostat...\n");
  status->isThermostatEnabled = false;
}

void adjustTemperature(HomeStatus* status, int temperature) {
  printf("Adjusting temperature to %d...\n", temperature);
  status->currentTemperature = temperature;
}

int main() {
  HomeStatus myHome = {
    .isLightsOn = false,
    .isThermostatEnabled = false,
    .currentTemperature = 72
  };

  turnOnLights(&myHome);
  enableThermostat(&myHome);
  adjustTemperature(&myHome, 68);
  turnOffLights(&myHome);

  return 0;
}