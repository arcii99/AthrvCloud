//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for traffic light timers
#define GREEN_TIME 120
#define YELLOW_TIME 30
#define RED_TIME 60

// Structure for traffic light
struct TrafficLight {
  int state;
  int timer;
};

// Function to print the current state of traffic light
void print_traffic_light(struct TrafficLight light) {
  if (light.state == 0) {
    printf("GREEN\n");
  } else if (light.state == 1) {
    printf("YELLOW\n");
  } else {
    printf("RED\n");
  }
}

// Function to update the timer of traffic light
void update_timer(struct TrafficLight *light, int time) {
  light->timer -= time;

  if (light->timer <= 0) {
    // If timer runs out, change state
    if (light->state == 0) {
      light->state = 1;
      light->timer = YELLOW_TIME;
    } else if (light->state == 1) {
      light->state = 2;
      light->timer = RED_TIME;
    } else {
      light->state = 0;
      light->timer = GREEN_TIME;
    }
  }
}

int main() {
  // Seed random number generator
  srand(time(NULL));

  // Initialize traffic light
  struct TrafficLight traffic_light = {rand() % 3, GREEN_TIME};

  while (1) {
    // Print current state of traffic light
    print_traffic_light(traffic_light);

    // Update timer of traffic light
    update_timer(&traffic_light, 1);

    // Wait for one second
    sleep(1);
  }

  return 0;
}