//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
   int command;
   int speed = 0;
   int steering = 0;
   
   while(1) {
      printf("Enter a command (0 = stop, 1 = forward, 2 = backward, 3 = left, 4 = right): ");
      scanf("%d", &command);
      
      switch(command) {
         case 0:
         speed = 0;
         steering = 0;
         break;

         case 1:
         speed = 100;
         break;

         case 2:
         speed = -100;
         break;

         case 3:
         steering = -50;
         break;

         case 4:
         steering = 50;
         break;
         
         default:
         printf("Invalid command! Please try again.\n");
      }
      printf("Speed: %d   Steering: %d\n", speed, steering);
   }
   
   return 0;
}