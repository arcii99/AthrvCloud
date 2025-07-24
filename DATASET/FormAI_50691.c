//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
   char input;
   
   printf("Welcome to Drone Remote Control System!\n");
   printf("Please press W, A, S, or D keys to control the drone.\n");
   printf("Press Q to exit the program.\n");

   while(1) {
      input = getchar();

      switch(input) {
         case 'W':
         case 'w':
            printf("Drone moves forward.\n");
            break;
         case 'A':
         case 'a':
            printf("Drone moves left.\n");
            break;
         case 'S':
         case 's':
            printf("Drone moves backward.\n");
            break;
         case 'D':
         case 'd':
            printf("Drone moves right.\n");
            break;
         case 'Q':
         case 'q':
            printf("Exiting Drone Remote Control System...\n");
            exit(0);
         default:
            printf("Invalid input.\n");
            break;
      }
   }

   return 0;
}