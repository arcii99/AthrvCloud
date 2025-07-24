//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
   int choice, altitude = 0, direction = 0; // Initialize variables
   
   do {
      printf("Choose an option:\n");
      printf("1 - Increase altitude\n");
      printf("2 - Decrease altitude\n");
      printf("3 - Move left\n");
      printf("4 - Move right\n");
      printf("5 - Exit\n");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1:
            altitude++;
            printf("Altitude increased. Current altitude: %d \n", altitude); // Increase altitude
            break;
         case 2:
            altitude--;
            printf("Altitude decreased. Current altitude: %d \n", altitude); // Decrease altitude
            break;
         case 3:
            direction--;
            printf("Moved left. Current direction: %d \n", direction); // Move left
            break;
         case 4:
            direction++;
            printf("Moved right. Current direction: %d \n", direction); // Move right
            break;
         case 5:
            printf("Exiting program."); // Exit program
            exit(0);
         default:
            printf("Invalid choice. Please enter a valid option. \n"); // Invalid choice
            break;
      }
   } while(choice!=5);
   
   return 0;
}