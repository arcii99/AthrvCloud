//FormAI DATASET v1.0 Category: Smart home automation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Variables to simulate different sensors in a smart home system
bool motion_detected = false;
float temperature = 23.5;
bool door_locked = true;
bool lights_on = false;

// Function to simulate sending a message to a user's phone
void send_message(char* message) {
  printf("Message sent: %s\n", message);
}

int main() {
  // Check if there is motion detected
  if (motion_detected) {
    // If there is motion, send a message to the user's phone alerting them
    send_message("Motion detected in your home");

    // Check if the lights are off
    if (!lights_on) {
      // If the lights are off, turn them on
      lights_on = true;
      printf("Turning lights on\n");
    }
  }

  // Check if the temperature is above 25 degrees Celsius
  if (temperature > 25) {
    // If the temperature is above 25, send a message to the user's phone alerting them
    char message[50];
    sprintf(message, "Temperature in your home is %.1f degrees Celsius", temperature);
    send_message(message);
  }

  // Check if the door is locked
  if (!door_locked) {
    // If the door is unlocked, send a message to the user's phone alerting them
    send_message("Your front door is unlocked");
  }

  return 0;
}