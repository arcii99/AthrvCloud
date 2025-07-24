//FormAI DATASET v1.0 Category: Smart home automation ; Style: all-encompassing
// C Smart Home Automation Example

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants
#define TEMP_THRESHOLD 25 // Celsius
#define LIGHT_THRESHOLD 5000 // Lux
#define HUMIDITY_THRESHOLD 60 // %

// Define device statuses
bool isAirConditionerOn = false;
bool isLightOn = false;
bool isHumidifierOn = false;

// Define function to turn on/off devices
void toggleAirConditioner(bool status) {
  if(status) {
    printf("Air conditioner turned on.\n");
    isAirConditionerOn = true;
  } else {
    printf("Air conditioner turned off.\n");
    isAirConditionerOn = false;
  }
}

void toggleLight(bool status) {
  if(status) {
    printf("Light turned on.\n");
    isLightOn = true;
  } else {
    printf("Light turned off.\n");
    isLightOn = false;
  }
}

void toggleHumidifier(bool status) {
  if(status) {
    printf("Humidifier turned on.\n");
    isHumidifierOn = true;
  } else {
    printf("Humidifier turned off.\n");
    isHumidifierOn = false;
  }
}

int main() {
  // Define sensor values
  int temperature = 26;
  int lightIntensity = 5000;
  int humidity = 65;

  // Check if temperature is above threshold and turn on air conditioner
  if(temperature > TEMP_THRESHOLD && !isAirConditionerOn) {
    toggleAirConditioner(true);
  }

  // Check if light intensity is below threshold and turn on light
  if(lightIntensity < LIGHT_THRESHOLD && !isLightOn) {
    toggleLight(true);
  }

  // Check if humidity is below threshold and turn on humidifier
  if(humidity < HUMIDITY_THRESHOLD && !isHumidifierOn) {
    toggleHumidifier(true);
  }

  // Check if temperature has returned to normal and turn off air conditioner
  if(temperature <= TEMP_THRESHOLD && isAirConditionerOn) {
    toggleAirConditioner(false);
  }

  // Check if light intensity has increased and turn off light
  if(lightIntensity >= LIGHT_THRESHOLD && isLightOn) {
    toggleLight(false);
  }

  // Check if humidity has increased and turn off humidifier
  if(humidity >= HUMIDITY_THRESHOLD && isHumidifierOn) {
    toggleHumidifier(false);
  }

  return 0;
}