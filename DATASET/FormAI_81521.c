//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void updateLight(int curLight, int time) {
  printf("Current Light: ");
  switch(curLight) {
    case 0:
      printf("Green\n");
      if (time < 30)
        printf("Time left: %d seconds\n", 30-time);
      else
        printf("Changing to Yellow in 3 seconds...\n");
      break;
    case 1:
      printf("Yellow\n");
      if (time < 5)
        printf("Time left: %d seconds\n", 5-time);
      else
        printf("Changing to Red in 3 seconds...\n");
      break;
    case 2:
      printf("Red\n");
      if (time < 20)
        printf("Time left: %d seconds\n", 20-time);
      else
        printf("Changing to Green in 3 seconds...\n");
      break;
    default:
      printf("Error!\n");
  }
}

int main() {
  srand(time(NULL));
  int curLight = rand() % 3;
  int time = 0;
  updateLight(curLight, time);

  // loop for 60 seconds
  for (int i = 0; i < 60; i++) {
    printf("Time: %d\n", i+1);
    if (time == 30 && curLight == 0) {
      curLight = 1;
      time = 0;
    } else if (time == 5 && curLight == 1) {
      curLight = 2;
      time = 0;
    } else if (time == 20 && curLight == 2) {
      curLight = 0;
      time = 0;
    }
    updateLight(curLight, time);
    time++;
    // wait for 1 second before updating again
    sleep(1);
  }

  // program ends after 60 seconds
  printf("Program has ended.\n");

  return 0;
}