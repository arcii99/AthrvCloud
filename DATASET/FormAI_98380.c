//FormAI DATASET v1.0 Category: Robot movement control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
   int x_pos = 0, y_pos = 0; // Initial position of the robot
   char direction = 'N'; // Initial direction of the robot
   int distance = 0; // Distance to move the robot
   char again = 'Y'; // Ask the user if they want to move again
   
   printf("Welcome to the Romeo and Juliet Robot Control Program\n");
   printf("The robot is at position (0, 0)\n");
   printf("Please enter the direction you want the robot to face (N, S, E, W):\n");
   scanf(" %c", &direction);
   
   while(again == 'Y' || again == 'y') {
      printf("Enter the distance you want the robot to move:\n");
      scanf("%d", &distance);
      
      switch(direction) {
         case 'N':
         y_pos += distance;
         break;

         case 'S':
         y_pos -= distance;
         break;

         case 'E':
         x_pos += distance;
         break;

         case 'W':
         x_pos -= distance;
         break;
      }
      
      printf("The robot is now at position (%d, %d)\n", x_pos, y_pos);
      printf("Do you want to move the robot again? (Y/N)\n");
      scanf(" %c", &again);
   }
   
   printf("Thank you for using the Romeo and Juliet Robot Control Program!\n");
   return 0;
}