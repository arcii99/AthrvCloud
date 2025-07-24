//FormAI DATASET v1.0 Category: Robot movement control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MOVE_FORWARD 1
#define MOVE_BACKWARD -1
#define TURN_LEFT -1
#define TURN_RIGHT 1
#define GRID_SIZE 10

typedef struct {
   int x;
   int y;
   int direction;
} Robot;

bool should_move_forward(Robot robot) {
   return (robot.direction == 0 && robot.y < GRID_SIZE)      || 
          (robot.direction == 1 && robot.x < GRID_SIZE)      || 
          (robot.direction == 2 && robot.y > 0)              || 
          (robot.direction == 3 && robot.x > 0);
}

Robot move_forward(Robot robot) {
   switch(robot.direction) {
      case 0:
         robot.y++;
         break;
      case 1:
         robot.x++;
         break;
      case 2:
         robot.y--;
         break;
      case 3:
         robot.x--;
         break;
   }
   return robot;
}

int main() {
   Robot robot = {0, 0, 0}; // x, y, 0 = north, 1 = east, 2 = south, 3 = west
   srand(time(NULL)); // seed random number generator with current time
   while(true) {
      int rand_num = rand() % 3;
      if(should_move_forward(robot)) {
         robot = move_forward(robot);
         printf("Moved forward: (%d, %d)\n", robot.x, robot.y);
      } else { // turn robot
         if(rand_num == 0) {
            robot.direction = (robot.direction + TURN_LEFT + 4) % 4; // ensure direction is positive
            printf("Turned left: %d\n", robot.direction);
         } else if(rand_num == 1) {
            robot.direction = (robot.direction + TURN_RIGHT) % 4; // ensure direction is less than 4
            printf("Turned right: %d\n", robot.direction);
         } else { // robot cannot move forward or turn, so stop
            printf("Stopped at (%d, %d)\n", robot.x, robot.y);
            break;
         }
      }
   }
   return 0;
}