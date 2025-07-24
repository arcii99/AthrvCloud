//FormAI DATASET v1.0 Category: Smart home automation ; Style: grateful
#include <stdio.h>
#include <stdbool.h>

// Define device types
#define THERMOSTAT 1
#define LIGHTS 2
#define SECURITY 3

// Define sensor types
#define MOTION_SENSOR 1
#define TEMPERATURE_SENSOR 2

// Define device states
#define ON 1
#define OFF 0

// Define temperature thresholds
#define TEMPERATURE_MIN 20
#define TEMPERATURE_MAX 30

// Global variables
int currentTemperature = 25;
bool motionDetected = false;
bool alarmActivated = false;
bool lightsOn = false;

// Function prototypes
void readSensors();
void controlDevices();

int main() {
  // Main loop
  while (true) {
    // Read sensors
    readSensors();
    
    // Control devices
    controlDevices();
  }
  
  return 0;
}

void readSensors() {
  // Simulate temperature sensor reading
  currentTemperature += (rand() % 5) - 2; // Add a random value between -2 and 2
  if (currentTemperature < TEMPERATURE_MIN) {
    currentTemperature = TEMPERATURE_MIN;
  }
  else if (currentTemperature > TEMPERATURE_MAX) {
    currentTemperature = TEMPERATURE_MAX;
  }
  
  // Simulate motion sensor reading
  motionDetected = rand() % 2;
}

void controlDevices() {
  if (currentTemperature > TEMPERATURE_MAX && !alarmActivated) {
    // Activate security system
    printf("Temperature is too high! Activating security system...\n");
    alarmActivated = true;
    // Turn off lights
    if (lightsOn) {
      printf("Turning off lights...\n");
      lightsOn = false;
    }
  }
  else if (motionDetected && !alarmActivated) {
    // Activate lights
    printf("Motion detected! Turning on lights...\n");
    lightsOn = true;
  }
  else if (currentTemperature < TEMPERATURE_MIN && !lightsOn) {
    // Turn on lights
    printf("Temperature is too low! Turning on lights...\n");
    lightsOn = true;
  }
  else if (!motionDetected && lightsOn) {
    // Turn off lights
    printf("No motion detected! Turning off lights...\n");
    lightsOn = false;
  }
}