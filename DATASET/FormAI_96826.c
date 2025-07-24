//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
   printf("Welcome to the Remote Control Vehicle Simulator!\n");
   printf("Please select from the following options:\n");
   printf("1. Move Forward\n");
   printf("2. Move Backward\n");
   printf("3. Turn Left\n");
   printf("4. Turn Right\n");
   printf("5. Emergency Stop\n");

   int choice;

   do {
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch(choice) {
           case 1:
               printf("Moving forward...\n");
               break;
           case 2:
               printf("Moving backward...\n");
               break;
           case 3:
               printf("Turning left...\n");
               break;
           case 4:
               printf("Turning right...\n");
               break;
           case 5:
               printf("Emergency stop! All systems shut down!... Just kidding! Ha! Gotcha, didn't I? You thought your code had some sort of error, didn't you?\n");
               exit(0);
           default:
               printf("Invalid choice. Please try again.\n");
       }
       
   } while(choice != 5);

   return 0;
}