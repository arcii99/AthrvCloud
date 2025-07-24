//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
   char command;

   printf("Press 1 for Red Light, 2 for Yellow Light, 3 for Green Light, or 0 to exit:\n");

   while (command != '0') {
      scanf("%c", &command);

      switch (command) {
         case '1':
            printf("Red Light\n");
            break;
         case '2':
            printf("Yellow Light\n");
            break;
         case '3':
            printf("Green Light\n");
            break;
         case '0':
            printf("Exiting...\n");
            break;
         default:
            printf("Invalid command, please try again.\n");
            break;
      }
   }

   return 0;
}