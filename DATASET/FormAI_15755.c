//FormAI DATASET v1.0 Category: Smart home light control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

struct Light {
  char name[MAX_NAME_LEN];
  int state;
  int brightness;
};

void turn_on(struct Light *light) {
  light->state = 1;
  printf("%s turned on\n", light->name);
}

void turn_off(struct Light *light) {
  light->state = 0;
  printf("%s turned off\n", light->name);
}

void set_brightness(struct Light *light, int brightness) {
  light->brightness = brightness;
  printf("%s brightness set to %d\n", light->name, brightness);
}

int main() {
  struct Light kitchen_light = { "Kitchen Light", 0, 0 };
  struct Light living_room_light = { "Living Room Light", 0, 0 };
  struct Light bedroom_light = { "Bedroom Light", 0, 0 };

  turn_on(&kitchen_light);
  set_brightness(&kitchen_light, 50);

  turn_on(&living_room_light);
  set_brightness(&living_room_light, 100);

  turn_on(&bedroom_light);
  set_brightness(&bedroom_light, 75);
  
  turn_off(&kitchen_light);
  turn_off(&living_room_light);
  turn_off(&bedroom_light);

  return 0;
}