//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: brave
#include <stdio.h>

int main() {
   int speed = 0; // initial speed is 0
   char direction = 'N'; // initial direction is North
   
   printf("Welcome to the Remote Control Vehicle Simulation!\n");
   printf("Use the arrow keys to control the vehicle and Q to quit.\n");
   
   while (1) { // infinite loop until user quits
      char input = getchar();
      
      switch(input) {
         case 'q':
         case 'Q':
            printf("Goodbye!\n");
            return 0;
         case 'w':
         case 'W':
            speed++; // increase speed when 'w' is pressed
            printf("Speed increased to %d.\n", speed);
            break;
         case 's':
         case 'S':
            if (speed == 0) {
               printf("Vehicle is already stopped.\n");
            } else {
               speed--; // decrease speed when 's' is pressed
               printf("Speed decreased to %d.\n", speed);
            }
            break;
         case 'a':
         case 'A':
            direction = 'W'; // change direction to West when 'a' is pressed
            printf("Direction changed to West.\n");
            break;
         case 'd':
         case 'D':
            direction = 'E'; // change direction to East when 'd' is pressed
            printf("Direction changed to East.\n");
            break;
         case ' ':
            printf("Vehicle stopped.\n");
            speed = 0; // stop vehicle when space bar is pressed
            break;
         default:
            printf("Invalid input.\n");
            break;
      }
   }
   return 0;
}