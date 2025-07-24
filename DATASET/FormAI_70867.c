//FormAI DATASET v1.0 Category: Smart home light control ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

int main() {
  printf("Welcome to Smart Home Light Control!\n");
  printf("Initializing system...\n");
  int current_time = 2000; // military time
  int light_intensity = 50; // start at 50%
  int motion_detected = 0; // no motion initially

  while(1) {
    // check motion sensor
    if(motion_detected) {
      printf("Motion detected!\n");
      light_intensity = 100;
    }
    else {
      light_intensity = 50;
    }

    // simulate time passing every 10 seconds
    current_time += 100;
    if(current_time >= 2400) {
      current_time = 0;
    }

    // changes light intensity based on time of day
    if(current_time >= 600 && current_time <= 1800) {
      light_intensity += 10;
    }
    else if(current_time > 1800 && current_time < 2200) {
      light_intensity -= 20;
    }
    else {
      light_intensity -= 5;
    }

    // make sure light intensity is within bounds
    if(light_intensity > 100) {
      light_intensity = 100;
    }
    else if(light_intensity < 0) {
      light_intensity = 0;
    }

    // output current light intensity
    printf("Current time: %d, Light intensity: %d%%\n", current_time, light_intensity);
    
    // simulate motion detection every 30 seconds
    if(current_time % 300 == 0) {
      motion_detected = rand() % 2; // randomly generate motion detection
    }
    
    // wait 10 seconds before checking again
    printf("Waiting 10 seconds...\n");
    sleep(10);
  }
  return 0;
}