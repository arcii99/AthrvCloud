//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main() {
  int current_light = RED;
  
  while (1) {
    // Red light
    if (current_light == RED) {
      printf("RED\n");
      sleep(5);
      current_light = GREEN;
    }
    // Yellow light
    else if (current_light == YELLOW) {
      printf("YELLOW\n");
      sleep(2);
      current_light = RED;
    }
    // Green light
    else if (current_light == GREEN) {
      printf("GREEN\n");
      sleep(7);
      current_light = YELLOW;
    }
  }

  return 0;
}