//FormAI DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function declarations
void turn_on_light();
void turn_off_light();
void lock_door();
void unlock_door();
void set_thermostat(int temp);

// State variables
bool is_light_on = false;
bool is_door_locked = false;
int current_temperature = 70;

// Main program
int main() {
  printf("Welcome home! Initializing smart home systems...\n");

  // Simulate asynchronous events
  srand(time(NULL)); // Seed random number generator
  for(int i = 0; i < 10; i++) {
    int event = rand() % 4 + 1; // Generate random event
    switch(event) {
      case 1:
        printf("\nMotion detected, turning on light...\n");
        turn_on_light();
        break;
      case 2:
        printf("\nDoor opened, locking door...\n");
        lock_door();
        break;
      case 3:
        printf("\nDoor unlocked, unlocking door...\n");
        unlock_door();
        break;
      case 4:
        printf("\nTemperature change detected, adjusting thermostat...\n");
        int temp = rand() % 5 - 2; // Generate random temperature change (-2 to +2 degrees)
        set_thermostat(current_temperature + temp);
        break;
    }
  }

  return 0;
}

// Function definitions
void turn_on_light() {
  printf("Light turned on.\n");
  is_light_on = true;
}

void turn_off_light() {
  printf("Light turned off.\n");
  is_light_on = false;
}

void lock_door() {
  printf("Door locked.\n");
  is_door_locked = true;
}

void unlock_door() {
  printf("Door unlocked.\n");
  is_door_locked = false;
}

void set_thermostat(int temp) {
  if(temp < 60 || temp > 80) {
    printf("Invalid temperature setting.\n");
  } else {
    printf("Thermostat set to %d degrees.\n", temp);
    current_temperature = temp;
  }
}