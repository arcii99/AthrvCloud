//FormAI DATASET v1.0 Category: Robot movement control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100

typedef struct {
   int x;
   int y;
} Position;

typedef struct {
   Position pos;
   int speed;
   int direction;
} Robot;

void move(Robot *r, int distance) {
   r->pos.x += distance;
}

void turn(Robot *r, int direction) {
   r->direction = direction;
}

int main() {
   Robot my_robot;
   my_robot.pos.x = 0;
   my_robot.pos.y = 0;
   my_robot.speed = 50;
   my_robot.direction = 0;

   printf("Robot starting at (%d, %d) with speed %d and direction %d\n",
          my_robot.pos.x, my_robot.pos.y, my_robot.speed, my_robot.direction);

   // Move forward 50 units
   move(&my_robot, 50);
   printf("Robot moved forward to (%d, %d)\n", my_robot.pos.x, my_robot.pos.y);

   // Turn left and move forward 30 units
   turn(&my_robot, 90);
   move(&my_robot, 30);
   printf("Robot turned and moved to (%d, %d)\n", my_robot.pos.x, my_robot.pos.y);

   // Turn right and move forward 20 units
   turn(&my_robot, -90);
   move(&my_robot, 20);
   printf("Robot turned and moved to (%d, %d)\n", my_robot.pos.x, my_robot.pos.y);

   // Move backwards 10 units
   turn(&my_robot, 180);
   move(&my_robot, -10);
   printf("Robot moved backwards to (%d, %d)\n", my_robot.pos.x, my_robot.pos.y);

   return 0;
}