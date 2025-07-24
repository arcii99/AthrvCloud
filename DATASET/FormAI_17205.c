//FormAI DATASET v1.0 Category: Robot movement control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 512
#define MIN_SPEED 0

int main()
{
   int speed = MIN_SPEED;
   char direction;

   printf("Welcome to Robot Movement Control!\n");

   while(1) {

      printf("Enter direction (F - forward, B - backward, L - left, R - right): ");
      scanf(" %c", &direction);

      switch(direction) {
         case 'F':
            speed += 64;
            if(speed > MAX_SPEED)
               speed = MAX_SPEED;
            printf("Moving forward with speed %d\n", speed);
            break;

         case 'B':
            speed -= 64;
            if(speed < MIN_SPEED)
               speed = MIN_SPEED;
            printf("Moving backward with speed %d\n", speed);
            break;

         case 'L':
            printf("Moving left\n");
            break;

         case 'R':
            printf("Moving right\n");
            break;

         default:
            printf("Invalid direction entered!");
            break;
      }
   }

   return 0;
}