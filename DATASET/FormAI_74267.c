//FormAI DATASET v1.0 Category: Smart home light control ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>

#define MAX_LIGHTS 4

typedef struct {
  bool is_on;
  int brightness;
} Light;

Light lights[MAX_LIGHTS];

void turn_on(int light_index) {
  lights[light_index].is_on = true;
}

void turn_off(int light_index) {
  lights[light_index].is_on = false;
}

void set_brightness(int light_index, int brightness) {
  if (brightness >= 0 && brightness <= 100) {
    lights[light_index].brightness = brightness;
  }
}

int main() {
  // initialize all lights to off state with 0 brightness
  for (int i = 0; i < MAX_LIGHTS; i++) {
    lights[i].is_on = false;
    lights[i].brightness = 0;
  }

  // turn on light 1 and set brightness to 50%
  turn_on(0);
  set_brightness(0, 50);

  // turn on light 2 and set brightness to 20%
  turn_on(1);
  set_brightness(1, 20);

  // turn off light 3
  turn_off(2);

  // print the current state of all lights
  for (int i = 0; i < MAX_LIGHTS; i++) {
    printf("Light %d: %s, brightness: %d%%\n",
           i + 1,
           lights[i].is_on ? "ON" : "OFF",
           lights[i].brightness);
  }

  return 0;
}