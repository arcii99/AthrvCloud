//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

typedef struct {
  int x;
  int y;
} Position;

Position vehicle;

void update_position(int dx, int dy) {
  int new_x = vehicle.x + dx;
  int new_y = vehicle.y + dy;

  if (new_x < 0 || new_x >= MAP_WIDTH || new_y < 0 || new_y >= MAP_HEIGHT) {
    printf("You're hitting the wall! Game over!\n");
    exit(0);
  }

  vehicle.x = new_x;
  vehicle.y = new_y; 
}

void draw_map() {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      if (x == vehicle.x && y == vehicle.y) {
        printf("X");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

void move_up_async() {
  sleep(1);
  update_position(0, -1);
}

void move_down_async() {
  sleep(1);
  update_position(0, 1);
}

void move_left_async() {
  sleep(1);
  update_position(-1, 0);
}

void move_right_async() {
  sleep(1);
  update_position(1, 0);
}

int main(void) {
  srand(time(NULL));

  vehicle.x = rand() % MAP_WIDTH;
  vehicle.y = rand() % MAP_HEIGHT;

  printf("Welcome to the Remote Control Vehicle Simulation!\n");
  printf("Use the arrow keys to move the vehicle. Press q to exit.\n");

  while (1) {
    draw_map();

    char input = getchar();

    if (input == 'q') {
      printf("Goodbye!\n");
      exit(0);
    } else if (input == '\033') {
      // arrow key
      getchar(); // skip the [
      input = getchar();

      if (input == 'A') {
        pthread_t thread;
        pthread_create(&thread, NULL, move_up_async, NULL);
      } else if (input == 'B') {
        pthread_t thread;
        pthread_create(&thread, NULL, move_down_async, NULL);
      } else if (input == 'C') {
        pthread_t thread;
        pthread_create(&thread, NULL, move_right_async, NULL);
      } else if (input == 'D') {
        pthread_t thread;
        pthread_create(&thread, NULL, move_left_async, NULL);
      }
    }
  }

  return 0;
}