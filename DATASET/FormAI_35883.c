//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
   int x, y;
   char ch;

   printf("Welcome to the Drone Remote Control Program!\n");
   printf("Press 'w' to move forward, 's' to move backwards, 'a' to turn left, 'd' to turn right, and 'q' to quit.\n");

   while (1) {
      printf("Enter a command: ");
      scanf("%c", &ch);

      switch (ch) {
         case 'w':
            printf("Drone is moving forward.\n");
            break;
         case 's':
            printf("Drone is moving backwards.\n");
            break;
         case 'a':
            printf("Drone is turning left.\n");
            break;
         case 'd':
            printf("Drone is turning right.\n");
            break;
         case 'q':
            printf("Exiting program. Goodbye!\n");
            exit(0);
         default:
            printf("Invalid command. Please try again.\n");
            break;
      }
      while ((getchar()) != '\n');
   }
   return 0;
}