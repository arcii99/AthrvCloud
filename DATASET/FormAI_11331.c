//FormAI DATASET v1.0 Category: Robot movement control ; Style: introspective
/*Introspective C Robot movement control program*/

/* This program provides movement control for a robot with two wheel motors */

#include <stdio.h>

int main() {
   printf("Welcome to the Introspective C Robot Movement Control program!\n");

   int wheel_speed_left = 0;   // speed of left wheel motor
   int wheel_speed_right = 0;  // speed of right wheel motor

   printf("Enter desired wheel speed for left motor (0-255): ");
   scanf("%d", &wheel_speed_left);

   printf("Enter desired wheel speed for right motor (0-255): ");
   scanf("%d", &wheel_speed_right);

   // Checking if input values are in range
   if (wheel_speed_left < 0 || wheel_speed_left > 255) {
      printf("Invalid speed entered for left wheel motor!\n");
   }

   if (wheel_speed_right < 0 || wheel_speed_right > 255) {
      printf("Invalid speed entered for right wheel motor!\n");
   }

   // Movement control logic
   if (wheel_speed_left > wheel_speed_right) {
      printf("Robot will turn right\n");
   } else if (wheel_speed_right > wheel_speed_left) {
      printf("Robot will turn left\n");
   } else {
      printf("Robot will move forward\n");
   }

   return 0;
}