//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

void change_light(int* light) {
  int current_light = *light;

  switch(current_light) {
    case RED:
      *light = GREEN;
      break;
    case YELLOW:
      *light = RED;
      break;
    case GREEN:
      *light = YELLOW;
      break;
  }
}

void print_light(int light) {
  switch(light) {
    case RED:
      printf("Red\n");
      break;
    case YELLOW:
      printf("Yellow\n");
      break;
    case GREEN:
      printf("Green\n");
      break;
  }
}

int main() {
  int light = RED;
  int countdown = 10;

  srand(time(0));

  while (countdown > 0) {
    printf("Time remaining: %d seconds\n", countdown);
    print_light(light);

    change_light(&light);

    //randomly add 1-5 seconds to countdown
    int rand_num = (rand() % 5) + 1;
    countdown += rand_num;

    printf("\n");

    //wait one second
    sleep(1);

    countdown--;
  }

  printf("Time's up!\n");

  return 0;
}