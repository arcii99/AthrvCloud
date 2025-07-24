//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
   int dronePower;
   char direction;

   printf("Welcome to Drone Remote Control\n");
   printf("Enter Drone Power Level (1-100): ");
   scanf("%d", &dronePower);

   if (dronePower >= 50) {
       printf("Drone Ready for Flight!\n");

       while (1) {
          printf("\nEnter Direction (f/b/l/r): ");
          scanf(" %c", &direction);

          switch(direction) {
             case 'f':
                 printf("Drone moving forward\n");
                 break;
             case 'b':
                 printf("Drone moving backward\n");
                 break;
             case 'l':
                 printf("Drone moving left\n");
                 break;
             case 'r':
                 printf("Drone moving right\n");
                 break;
             default:
                 printf("Invalid direction. Please try again.\n");
                 break;
          }
       }
   }
   else {
       printf("Drone power level is too low. Charge your drone or increase power level before flying.");
       return 0;
   }
}