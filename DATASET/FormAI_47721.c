//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int red = 1, yellow = 0, green = 0;

  while(1) {
    if(red) {
      printf("RED LIGHT ON\n");
      sleep(5); // Wait for 5 seconds
      red = 0;
      yellow = 1;
    }
    else if(yellow) {
      printf("YELLOW LIGHT ON\n");
      sleep(2); // Wait for 2 seconds
      yellow = 0;
      green = 1;
    }
    else if(green) {
      printf("GREEN LIGHT ON\n");
      sleep(7); // Wait for 7 seconds
      green = 0;
      yellow = 1;
    }
  }
  return 0;
}