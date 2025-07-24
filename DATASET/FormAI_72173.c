//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  srand(time(NULL)); // set random seed based on time

  int red_time, green_time, yellow_time; // initialize variables
  
  printf("Welcome to the Medieval Traffic Light Controller!\n\n");

  while(1) { // loop indefinitely

    printf("The traffic light is currently red.\n");

    red_time = (rand() % 10) + 1; // generate a random integer between 1 and 10
    printf("The red light will stay on for %d minutes.\n", red_time);

    sleep(red_time); // pause program for red light duration

    printf("The traffic light is now green!\n");

    green_time = (rand() % 10) + 1; // generate a random integer between 1 and 10
    printf("The green light will stay on for %d minutes.\n", green_time);

    sleep(green_time); // pause program for green light duration

    printf("The traffic light is now yellow.\n");

    yellow_time = (rand() % 5) + 1; // generate a random integer between 1 and 5
    printf("The yellow light will stay on for %d minutes.\n", yellow_time);

    sleep(yellow_time); // pause program for yellow light duration
  }

  return 0;
}