//FormAI DATASET v1.0 Category: Robot movement control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

   int pos_x = 0;
   int pos_y = 0;
   int direction = 0;

   srand(time(NULL));

   printf("Current position: X = %d, Y = %d\n", pos_x, pos_y);

   for (int i = 0; i < 50; i++) {

      int move_distance = rand() % 10 + 1;

      // Decide the current direction of the robot
      char* robot_direction = NULL;

      if (direction == 0) {
         robot_direction = "FORWARD";
      } else if (direction == 1) {
         robot_direction = "BACKWARD";
      } else if (direction == 2) {
         robot_direction = "LEFT";
      } else {
         robot_direction = "RIGHT";
      }

      printf("MOVING %s by %d units.\n", robot_direction, move_distance);

      // Update the position of the robot based on the direction
      if (direction == 0) {
         pos_y += move_distance;
      } else if (direction == 1) {
         pos_y -= move_distance;
      } else if (direction == 2) {
         pos_x -= move_distance;
      } else {
         pos_x += move_distance;
      }

      printf("Current position: X = %d, Y = %d\n", pos_x, pos_y);

      // Decide the new direction of the robot
      int turn = rand() % 2;
      if (turn == 0) { // Turn left
         direction = (direction - 1 + 4) % 4;
      } else { // Turn right
         direction = (direction + 1) % 4;
      }
   }

   printf("Final position: X = %d, Y = %d\n", pos_x, pos_y);

   return 0;
}