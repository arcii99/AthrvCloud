//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

void accelerate(int *speed) {  // function to simulate acceleration
   if (*speed < MAX_SPEED) {
      *speed += 10;
   }
   printf("Vehicle is now traveling at %d mph.\n", *speed);
}

void decelerate(int *speed) {  // function to simulate deceleration
   if (*speed > MIN_SPEED) {
      *speed -= 10;
   }
   printf("Vehicle is now traveling at %d mph.\n", *speed);
}

int main() {
   int speed = 0;

   printf("Welcome to the remote control vehicle simulation!\n");
   printf("To accelerate, press '1'. To decelerate, press '2'. To exit, press '0'.\n");

   int input;
   do {
      printf("Enter your selection: ");
      scanf("%d", &input);

      switch (input) {
         case 0:
            printf("Exiting simulation...\n");
            break;
         case 1:
            accelerate(&speed);  // pass address of speed variable
            break;
         case 2:
            decelerate(&speed);  // pass address of speed variable
            break;
         default:
            printf("Invalid selection. Please try again.\n");
      }
   } while (input != 0);

   return 0;
}