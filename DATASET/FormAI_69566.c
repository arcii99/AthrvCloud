//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>

int main() {
   /* Initializing variables */
   int speed = 0;
   int direction = 0;
   int x = 0;
   int y = 0;

   /* Loop for continuous control */
   while(1) {
      /* Getting user input */
      printf("Enter speed (0-10): ");
      scanf("%d", &speed);
      printf("Enter direction (0-360): ");
      scanf("%d", &direction);

      /* Converting direction to x and y coordinates */
      double radians = direction * 3.1415926535/180.0;
      x = (int)(speed * cos(radians));
      y = (int)(speed * sin(radians));

      /* Printing out vehicle status */
      printf("Target point: (%d, %d), Speed: %d, Direction: %d\n", x, y, speed, direction);
   }

   return 0;
}