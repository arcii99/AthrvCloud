//FormAI DATASET v1.0 Category: Robot movement control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x = 0, y = 0;

   printf("Please enter the direction you want the robot to move in (N, S, E, W): ");
   char direction = getchar();

   switch (direction) {
      case 'N':
         y++;
         break;
      case 'S':
         y--;
         break;
      case 'E':
         x++;
         break;
      case 'W':
         x--;
         break;
      default:
         printf("Invalid direction.");
         exit(1);
   }

   printf("Robot moved to position (%d, %d)\n", x, y);

   return 0;
}