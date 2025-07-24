//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize random seed

  int red_light_time = 5 + rand() % 6; // random time for red light between 5 and 10 seconds
  int green_light_time = 10 + rand() % 11; // random time for green light between 10 and 20 seconds
  int yellow_light_time = 2 + rand() % 3; // random time for yellow light between 2 and 4 seconds
  char current_light = 'r'; // current light is initially red

  int time_left; // time left for current light
  printf("Traffic light controller starting...\n");
  printf("Red light time is %d seconds\n", red_light_time);
  printf("Green light time is %d seconds\n", green_light_time);
  printf("Yellow light time is %d seconds\n", yellow_light_time);

  while (1) { // loop forever
    if (current_light == 'r') {
      // red light is on
      time_left = red_light_time;
      printf("Red light is on for %d seconds\n", time_left);
      while (time_left > 0) {
        printf("%d seconds left\n", time_left);
        sleep(1); // wait for 1 second
        time_left--;
      }
      current_light = 'g'; // switch to green light
    } else if (current_light == 'g') {
      // green light is on
      time_left = green_light_time;
      printf("Green light is on for %d seconds\n", time_left);
      while (time_left > 0) {
        printf("%d seconds left\n", time_left);
        sleep(1); // wait for 1 second
        time_left--;
      }
      current_light = 'y'; // switch to yellow light
    } else {
      // yellow light is on
      time_left = yellow_light_time;
      printf("Yellow light is on for %d seconds\n", time_left);
      while (time_left > 0) {
        printf("%d seconds left\n", time_left);
        sleep(1); // wait for 1 second
        time_left--;
      }
      current_light = 'r'; // switch to red light
    }
  }

  return 0;
}