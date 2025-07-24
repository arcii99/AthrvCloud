//FormAI DATASET v1.0 Category: Robot movement control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {LEFT, RIGHT, UP, DOWN} direction;
typedef enum {STOPPED, MOVING} status;

typedef struct {
  int x;
  int y;
  direction dir;
  status state;
} robot;

int move_robot(robot *r, int distance) {
  switch (r->dir) {
    case LEFT:
      if (r->x - distance >= 0) {
        r->x -= distance;
        return 1;
      } else {
        return 0;
      }
    case RIGHT:
      if (r->x + distance <= 100) {
        r->x += distance;
        return 1;
      } else {
        return 0;
      }
    case UP:
      if (r->y + distance <= 100) {
        r->y += distance;
        return 1;
      } else {
        return 0;
      }
    case DOWN:
      if (r->y - distance >= 0) {
        r->y -= distance;
        return 1;
      } else {
        return 0;
      }
    default:
      return 0;
  }
}

int turn_robot(robot *r, direction dir) {
  switch (dir) {
    case LEFT:
      r->dir = LEFT;
      return 1;
    case RIGHT:
      r->dir = RIGHT;
      return 1;
    case UP:
      r->dir = UP;
      return 1;
    case DOWN:
      r->dir = DOWN;
      return 1;
    default:
      return 0;
  }
}

void print_robot(robot *r) {
  printf("Robot location:(%d, %d)\n", r->x, r->y);
  printf("Robot direction: ");
  switch (r->dir) {
    case LEFT:
      printf("LEFT\n");
      break;
    case RIGHT:
      printf("RIGHT\n");
      break;
    case UP:
      printf("UP\n");
      break;
    case DOWN:
      printf("DOWN\n");
      break;
  }
}

int main() {
  robot r = {50, 50, UP, STOPPED};
  
  printf("Initial position:\n");
  print_robot(&r);
  
  // Move robot up by 25
  r.state = MOVING;
  for (int i = 0; i < 5; i++) {
    if (move_robot(&r, 5)) {
      print_robot(&r);
    } else {
      printf("Unable to move robot any further in this direction.\n");
      break;
    }
  }
  r.state = STOPPED;
  
  // Turn robot right
  turn_robot(&r, RIGHT);
  printf("Robot turned right.\n");
  print_robot(&r);
  
  // Move robot right by 25
  r.state = MOVING;
  for (int i = 0; i < 5; i++) {
    if (move_robot(&r, 5)) {
      print_robot(&r);
    } else {
      printf("Unable to move robot any further in this direction.\n");
      break;
    }
  }
  r.state = STOPPED;
  
  return 0;
}