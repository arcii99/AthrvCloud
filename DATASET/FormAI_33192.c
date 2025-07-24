//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
   int speed = 50;
   int height = 0;
   char direction = 'N';
   char response = 'Y';

   printf("Welcome to the C Drone Remote Control Program!\n");

   while (response == 'Y') {
      printf("Current drone speed: %d\n", speed);
      printf("Current drone height: %d\n", height);
      printf("Current drone direction: %c\n", direction);

      printf("Enter your next command:\n");
      printf("1. Change speed\n");
      printf("2. Change height\n");
      printf("3. Change direction\n");

      int command;
      scanf("%d", &command);

      switch(command) {
         case 1:
            printf("Enter new speed:\n");
            scanf("%d", &speed);
            break;
         case 2:
            printf("Enter new height:\n");
            scanf("%d", &height);
            break;
         case 3:
            printf("Enter new direction (N, S, E, W):\n");
            scanf(" %c", &direction);
            break;
         default:
            printf("Invalid command.\n");
      }

      printf("Do you want to continue? (Y/N)\n");
      scanf(" %c", &response);
   }

   printf("Thank you for using the C Drone Remote Control Program!\n");

   return 0;
}