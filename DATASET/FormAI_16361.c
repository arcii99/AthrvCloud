//FormAI DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
/* Smart Home Light Control Program */
/* By: [Your Name Here] */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROOMS 5
#define LIGHTS 4

/* Define struct for each light in a room */
typedef struct Light {
  bool isOn;
  int brightness; // 0-100
} Light;

/* Define struct for each room in the house */
typedef struct Room {
  Light lights[LIGHTS];
} Room;

/* Function to turn all lights in a room on or off */
void switchRoom(Room *room, bool isOn) {
  for(int i = 0; i < LIGHTS; i++) {
    room->lights[i].isOn = isOn;
    room->lights[i].brightness = isOn ? 100 : 0; // Set brightness to max or min depending on whether the light is on or off
  }
  printf("Lights in room turned %s\n", isOn ? "on" : "off");
}

/* Function to toggle a specific light in a room */
void toggleLight(Room *room, int lightNum) {
  if(lightNum < 0 || lightNum >= LIGHTS) {
    printf("Invalid light number. Please enter a number between 0 and %d\n", LIGHTS-1);
    return;
  }

  if(room->lights[lightNum].isOn) {
    room->lights[lightNum].isOn = false;
    room->lights[lightNum].brightness = 0;
    printf("Light %d turned off\n", lightNum);
  } else {
    room->lights[lightNum].isOn = true;
    room->lights[lightNum].brightness = 100;
    printf("Light %d turned on\n", lightNum);
  }
}

/* Function to set brightness of a specific light in a room */
void setLightBrightness(Room *room, int lightNum, int brightness) {
  if(lightNum < 0 || lightNum >= LIGHTS) {
    printf("Invalid light number. Please enter a number between 0 and %d\n", LIGHTS-1);
    return;
  }

  if(brightness < 0 || brightness > 100) {
    printf("Invalid brightness level. Please enter a number between 0 and 100\n");
    return;
  }

  room->lights[lightNum].brightness = brightness;
  if(brightness == 0) {
    room->lights[lightNum].isOn = false;
    printf("Light %d turned off\n", lightNum);
  } else {
    room->lights[lightNum].isOn = true;
    printf("Brightness of light %d set to %d\n", lightNum, brightness);
  }
}

int main() {
  Room house[ROOMS];

  /* Initialize random seed */
  srand(time(NULL));

  /* Initialize lights in each room */
  for(int i = 0; i < ROOMS; i++) {
    for(int j = 0; j < LIGHTS; j++) {
      house[i].lights[j].isOn = rand() % 2; // Randomly turn light on or off
      house[i].lights[j].brightness = house[i].lights[j].isOn ? rand() % 101 : 0; // Set brightness to random value between 0 and 100 if light is on, otherwise set brightness to 0
    }
  }

  /* Example usage of light control functions */
  switchRoom(&house[2], true); // Turn all lights in room 2 on
  toggleLight(&house[4], 2); // Toggle light 2 in room 4
  setLightBrightness(&house[1], 3, 75); // Set brightness of light 3 in room 1 to 75

  return 0;
}