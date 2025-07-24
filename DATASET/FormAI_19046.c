//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int speed(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

int main() {
  srand(time(0));

  printf("Welcome to the Remote Control Vehicle Simulation!\n");

  int direction = 0;
  int curr_pos = 0;
  int prev_pos = 0;
  int speed_min = 30;
  int speed_max = 60;
  int dist_max = 1000;
  int dist_min = 100;

  while(1) {
    // randomize speed and direction
    int curr_speed = speed(speed_min, speed_max);
    direction = rand() % 2 - 1;

    // update position
    curr_pos += curr_speed * direction;
    if(curr_pos > dist_max) {
      printf("Vehicle has reached the maximum distance of %d meters!\n", dist_max);
      return 0;
    } else if((curr_pos - prev_pos) < dist_min) {
      printf("Vehicle has collided! Game Over!\n");
      return 0;
    }

    // print status
    printf("Current position: %d meters\n", curr_pos);
    printf("Current speed: %d km/hour\n", curr_speed);
    printf("Direction: %s\n", (direction == 1) ? "right" : "left");
    printf("---------------------------------\n");

    // update previous position
    prev_pos = curr_pos;
  }

  return 0;
}