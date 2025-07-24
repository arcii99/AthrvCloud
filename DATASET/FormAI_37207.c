//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int current_light = RED;

void* traffic_light(void* arg) {

  while(1) {

    if(current_light == RED) {

      printf("Red light is on\n");
      sleep(5);
      current_light = GREEN;

    } else if(current_light == YELLOW) {

      printf("Yellow light is on\n");
      sleep(2);
      current_light = RED;

    } else if(current_light == GREEN) {

      printf("Green light is on\n");
      sleep(10);
      current_light = YELLOW;

    }
  }

  return NULL;
}

int main() {

  pthread_t t;
  pthread_create(&t, NULL, traffic_light, NULL);

  while(1) {
    if(current_light == RED) {
      printf("Stop\n");
    } else if(current_light == YELLOW) {
      printf("Prepare to go\n");
    } else if(current_light == GREEN) {
      printf("Go\n");
    }
    sleep(1);
  }

  return 0;
}