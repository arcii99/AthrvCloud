//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
   int command;
    
   printf("Welcome to C Drone Remote Control!\n");

   do {
      printf("\nEnter a command (1-4):\n");
      printf("1 - Takeoff\n");
      printf("2 - Land\n");
      printf("3 - Move up\n");
      printf("4 - Move down\n");
        
      scanf("%d", &command);

      switch(command) {
         case 1 :
            printf("\nDrone is taking off.");
            break;
         case 2 :
            printf("\nDrone is landing.");
            break;
         case 3 :
            printf("\nDrone is moving up.");
            break;
         case 4 :
            printf("\nDrone is moving down.");
            break;
         default :
            printf("\nInvalid command. Please enter a command between 1-4.");
      }
   } while(command != 2);

   printf("\nDrone has landed. Goodbye!");

   return 0;
}