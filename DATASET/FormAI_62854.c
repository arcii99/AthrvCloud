//FormAI DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define the states for the light
typedef enum {
  OFF = 0,
  ON = 1,
} LightState;

// Define the light data structure
typedef struct Light {
  char* name;
  uint8_t brightness;
  LightState state;
} Light;

// Define the home data structure
typedef struct Home {
  char* name;
  uint8_t numLights;
  Light* lights;
} Home;

// Function to turn a light on
void turnOn(Light* light) {
  light->state = ON;
  printf("%s turned on\n", light->name);
}

// Function to turn a light off
void turnOff(Light* light) {
  light->state = OFF;
  printf("%s turned off\n", light->name);
}

// Function to set the brightness of a light
void setBrightness(Light* light, uint8_t brightness) {
  light->brightness = brightness;
  printf("%s brightness set to %d\n", light->name, brightness);
}

// Function to add a new light to the home
void addLight(Home* home, char* name) {
  // Allocate memory for the new light
  home->numLights++;
  Light* newLight = (Light*) malloc(sizeof(Light));
  newLight->name = name;
  newLight->brightness = 100;
  newLight->state = OFF;

  // Reallocate memory for the array of lights
  home->lights = (Light*) realloc(home->lights, home->numLights * sizeof(Light));
  home->lights[home->numLights - 1] = *newLight;

  printf("%s added to %s\n", name, home->name);
}

// Main function
int main() {
  // Create a new home
  Home* myHome = (Home*) malloc(sizeof(Home));
  myHome->name = "My Home";
  myHome->numLights = 0;
  myHome->lights = NULL;

  // Add some lights to the home
  addLight(myHome, "Living Room Light");
  addLight(myHome, "Bedroom Light");
  addLight(myHome, "Kitchen Light");

  // Turn on the Living Room Light
  turnOn(&myHome->lights[0]);
  // Set the brightness of the Bedroom Light
  setBrightness(&myHome->lights[1], 50);
  // Turn off the Kitchen Light
  turnOff(&myHome->lights[2]);

  // Clean up memory
  for (int i = 0; i < myHome->numLights; i++) {
    free(myHome->lights[i].name);
  }
  free(myHome->lights);
  free(myHome);

  return 0;
}