//FormAI DATASET v1.0 Category: Robot movement control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int x = 0; // X-coordinate of the robot
   int y = 0; // Y-coordinate of the robot

   // Seed the random number generator with the current system time
   srand(time(NULL));

   // Generate 20 random movements for the robot
   for(int i = 0; i < 20; i++)
   {
      int direction = rand() % 4; // Randomly choose a direction: 0, 1, 2, or 3
      int distance = rand() % 6 + 1; // Randomly choose a distance: 1-6
      
      // Move the robot according to the chosen direction and distance
      switch(direction)
      {
         case 0: // Move up
            y += distance;
            printf("Move up %d units\n", distance);
            break;
         case 1: // Move down
            y -= distance;
            printf("Move down %d units\n", distance);
            break;
         case 2: // Move left
            x -= distance;
            printf("Move left %d units\n", distance);
            break;
         case 3: // Move right
            x += distance;
            printf("Move right %d units\n", distance);
            break;
      }
   }

   // Print the final position of the robot
   printf("The robot is now at (%d,%d)\n", x, y);

   return 0;
}