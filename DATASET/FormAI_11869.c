//FormAI DATASET v1.0 Category: Smart home automation ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>

bool is_motion_detected = false;
bool is_light_on = false;

void detect_motion() {
  is_motion_detected = true;
}

void turn_on_light() {
  is_light_on = true;
}

void turn_off_light() {
  is_light_on = false;
}

int main(void) {
  printf("Welcome to the Smart Home Automation System!\n");

  while(true) {
    if(is_motion_detected && !is_light_on) {
      printf("Motion detected! Turning on the light!\n");
      turn_on_light();
    }

    if(!is_motion_detected && is_light_on) {
      printf("No more motion detected. Turning off the light.\n");
      turn_off_light();
    }
  }

  return 0;
}