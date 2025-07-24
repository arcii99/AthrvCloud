//FormAI DATASET v1.0 Category: Smart home light control ; Style: automated
#include <stdio.h>

// function to control light
void control_light(int state) {
  if(state == 1) {
    printf("Light is turned ON.\n");
  } else {
    printf("Light is turned OFF.\n");
  }
}

// function to check presence in the room
int check_presence() {
  int presence = 0;
  
  // logic to check for presence here
  // assuming presence is found
  presence = 1;
  
  return presence;
}

// function to check ambient light levels
int check_light_levels() {
  int light_levels = 0;
  
  // logic to check light levels here
  // assuming light levels are low
  light_levels = 1;
  
  return light_levels;
}

int main() {
  int presence, light_levels, time, light_state = 0;
  
  // loop to simulate continuous monitoring
  while(1) {
    // check for presence
    presence = check_presence();
    
    // if presence is detected, check light levels
    if(presence) {
      light_levels = check_light_levels();
      
      // if light levels are low and light is currently off, turn it on and record time
      if(light_levels && !light_state) {
        control_light(1);
        light_state = 1;
        time = 0;
      } else if(!light_levels && light_state) { // if light levels are high and light is currently on, turn it off
        control_light(0);
        light_state = 0;
        time = 0;
      } else if(light_state) { // increment time if light is currently on
        time++;
        
        // if light has been on for more than 1 hour, turn it off
        if(time >= 60) {
          control_light(0);
          light_state = 0;
          time = 0;
        }
      }
    }
    
    // delay for some time before checking again
    // assuming 10 seconds delay here
    sleep(10);
  }
  
  return 0;
}