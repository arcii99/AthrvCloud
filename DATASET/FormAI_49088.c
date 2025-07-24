//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>

int main() {
   int droneSpeed = 0;
   int droneAltitude = 0;
   char droneDirection = 'R';
   
   printf("Welcome to the Drone Remote Control Program!\n");

   while (1) {
       printf("\nCurrent Drone Stats:\n");
       printf("Speed: %d\n", droneSpeed);
       printf("Altitude: %d\n", droneAltitude);
       printf("Direction: %c\n\n", droneDirection);

       printf("Enter a command: ");
       char command = getchar();

       switch (command) {
           case 'w':
               droneAltitude += 10;
               break;
           case 's':
               droneAltitude -= 10;
               if (droneAltitude < 0) {
                   printf("Drone has crashed! Game over.\n");
                   return 0;
               }
               break;
           case 'a':
               if (droneDirection == 'U') {
                   droneDirection = 'L';
               } else if (droneDirection == 'L') {
                   droneDirection = 'D';
               } else if (droneDirection == 'D') {
                   droneDirection = 'R';
               } else if (droneDirection == 'R') {
                   droneDirection = 'U';
               }
               break;
           case 'd':
               if (droneDirection == 'U') {
                   droneDirection = 'R';
               } else if (droneDirection == 'R') {
                   droneDirection = 'D';
               } else if (droneDirection == 'D') {
                   droneDirection = 'L';
               } else if (droneDirection == 'L') {
                   droneDirection = 'U';
               }
               break;
           case ' ': // spacebar
               droneSpeed = 0;
               break;
           case '1':
               droneSpeed = 10;
               break;
           case '2':
               droneSpeed = 20;
               break;
           case '3':
               droneSpeed = 30;
               break;
           default:
               printf("Invalid command! Try again.\n");
       }

       // update drone position based on speed and direction
       if (droneDirection == 'U') {
           droneAltitude += droneSpeed;
       } else if (droneDirection == 'D') {
           droneAltitude -= droneSpeed;
           if (droneAltitude < 0) {
               printf("Drone has crashed! Game over.\n");
               return 0;
           }
       } else if (droneDirection == 'L') {
            droneSpeed = (int)droneSpeed/2;
            droneAltitude += droneSpeed;
       } else if (droneDirection == 'R') {
            droneSpeed = (int)droneSpeed/2;
            droneAltitude += droneSpeed;
       }
   }

   return 0;
}