//FormAI DATASET v1.0 Category: Robot movement control ; Style: funny
#include <stdio.h>

int main() {
   int direction = 1;
   float speed = 0.0;
   printf("Welcome to C Robot Movement Control System\n");
   printf("Please enter a valid speed and direction combination (ex: 5.5 1)\n");
   printf("Speed must be a floating point value between 0.0 and 10.0\n");
   printf("Direction must be either 1 or -1\n");

   while (1) {
      scanf("%f %d", &speed, &direction);

      if (speed < 0.0 || speed > 10.0) {
         printf("Invalid speed value. Please enter a value between 0.0 and 10.0\n");
         continue;
      }

      if (direction != 1 && direction != -1) {
         printf("Invalid direction value. Please enter either 1 or -1\n");
         continue;
      }

      if (speed == 0.0) {
         printf("Stopping C Robot. Goodbye!\n");
         break;
      }

      printf("Moving C Robot at a speed of %.1f in the %s direction\n", speed, (direction == 1 ? "forward" : "backward"));
      printf("Beep boop boop beep\n");

      // Simulate some movement for 1 second
      for (int i = 0; i < 100000000; i++) {
         // Do some calculations to simulate movement
      }

      // Randomly change direction
      if (rand() % 10 == 0) {
         direction *= -1;
         printf("Changing direction. Now moving in the %s direction\n", (direction == 1 ? "forward" : "backward"));
      }

      printf("Beep boop boop beep\n");
   }

   return 0;
}