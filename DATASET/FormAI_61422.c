//FormAI DATASET v1.0 Category: Smart home automation ; Style: multivariable
#include <stdio.h>

// Variable Declarations
int temperature = 25; // in Celsius
int lights[3] = {0, 0, 0}; // 0 for off, 1 for on
int blinds = 0; // 0 for closed, 1 for open
int music = 0; // 0 for off, 1 for on

// Function Declarations
void change_temperature(int new_temp);
void toggle_lights(int index);
void toggle_blinds();
void toggle_music();

int main() {
  // Initial state of the smart home
  printf("Smart Home Automation\n");
  printf("Current Temperature: %dC\n", temperature);
  printf("Lights: [%d, %d, %d]\n", lights[0], lights[1], lights[2]);
  printf("Blinds: %d\n", blinds);
  printf("Music: %d\n", music);

  // User interactions
  change_temperature(22);
  toggle_lights(2);
  toggle_blinds();
  toggle_music();

  // New state of the smart home
  printf("\nNew Smart Home Automation Settings\n");
  printf("Current Temperature: %dC\n", temperature);
  printf("Lights: [%d, %d, %d]\n", lights[0], lights[1], lights[2]);
  printf("Blinds: %d\n", blinds);
  printf("Music: %d\n", music);

  return 0;
}

void change_temperature(int new_temp) {
  temperature = new_temp;
}

void toggle_lights(int index) {
  if (index < 0 || index > 2) {
    printf("Invalid index for lights array.\n");
    return;
  }
  if (lights[index] == 0) {
    lights[index] = 1;
  } else {
    lights[index] = 0;
  }
}

void toggle_blinds() {
  if (blinds == 0) {
    blinds = 1;
  } else {
    blinds = 0;
  }
}

void toggle_music() {
  if (music == 0) {
    music = 1;
  } else {
    music = 0;
  }
}