//FormAI DATASET v1.0 Category: Robot movement control ; Style: Dennis Ritchie
#include <stdio.h>

/*
 * Simple Robot movement control program 
 */

int main() {
   int forward_facing = 1;
   int x_coord = 5, y_coord = 5;
   
   printf("Robot initialized at coordinates (%d, %d) facing forward.\n", x_coord, y_coord);
   
   // Robot movement control loop
   while(1) {
      // Read user input for robot movement controls
      char key_press = getchar();
      fflush(stdin);

      // Determine the action based on user input
      switch(key_press) {
         case 'w': // Move forward
            if(forward_facing) y_coord += 1;
            else y_coord -= 1;
            printf("Robot moved forward to coordinates (%d, %d).\n", x_coord, y_coord);
            break;
            
         case 's': // Move backward
            if(forward_facing) y_coord -= 1;
            else y_coord += 1;
            printf("Robot moved backward to coordinates (%d, %d).\n", x_coord, y_coord);
            break;
            
         case 'd': // Turn right
            forward_facing = 1;
            printf("Robot turned right and is now facing forward.\n");
            break;
            
         case 'a': // Turn left
            forward_facing = 0;
            printf("Robot turned left and is now facing backward.\n");
            break;
            
         case 'q': // Quit the program
            printf("Robot shut down.\n");
            return 0;
            
         default:
            printf("Unknown command.\n");
      }
   }
}