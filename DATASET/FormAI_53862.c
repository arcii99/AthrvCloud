//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));  // initialize random seed

  int speed = rand() % 101;  // generate random speed from 0 to 100
  printf("Calculating Internet Speed...\n");

  // simulate calculating speed
  for (int i = 0; i < 3; i++) {
    printf(".");
    sleep(1);
  }

  printf("\nYour Internet Speed: %d Mbps\n", speed);
  if (speed >= 50) {
    printf("Your Internet speed is great!\n");
  } else if (speed >= 25) {
    printf("Your Internet speed is okay.\n");
  } else {
    printf("Your Internet speed is slow.\n");
  }

  return 0;
}