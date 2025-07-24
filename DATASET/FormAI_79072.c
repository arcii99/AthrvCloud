//FormAI DATASET v1.0 Category: Robot movement control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  Position position;
  int speed;
} Robot;

void move_up(Position *position) {
  position->y += 1;
}

void move_down(Position *position) {
  position->y -= 1;
}

void move_left(Position *position) {
  position->x -= 1;
}

void move_right(Position *position) {
  position->x += 1;
}

void move_robot(Robot *robot, void (*move)(Position*)) {
  int chance = rand() % (MAX_SPEED + 1);

  if (chance <= robot->speed) {
    move(&robot->position);
    printf("Moved robot to (%d, %d)\n", robot->position.x, robot->position.y);
  } else {
    printf("Robot did not move\n");
  }
}

int main() {
  srand(time(NULL));

  Robot robot = {
    .position = {0, 0},
    .speed = 5
  };

  for (int i = 0; i < 10; i++) {
    int direction = rand() % 4;

    switch (direction) {
      case 0:
        move_robot(&robot, move_up);
        break;
      case 1:
        move_robot(&robot, move_down);
        break;
      case 2:
        move_robot(&robot, move_left);
        break;
      case 3:
        move_robot(&robot, move_right);
        break;
    }
  }

  return 0;
}