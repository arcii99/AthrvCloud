//FormAI DATASET v1.0 Category: Smart home light control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
   bool livingRoomLightsOn = false;
   bool kitchenLightsOn = false;
   bool bedroomLightsOn = false;

   printf("Welcome to Smart Home Light Control!\n");
   printf("Please enter the mode: (1) Manual or (2) Automatic\n");
   int mode;
   scanf("%d", &mode);

   if (mode == 1) {
      while (true) {
         printf("\nChoose a room to control:\n");
         printf("(1) Living room\n");
         printf("(2) Kitchen\n");
         printf("(3) Bedroom\n");
         int room;
         scanf("%d", &room);

         printf("\nChoose an action:\n");
         printf("(1) Turn on\n");
         printf("(2) Turn off\n");
         int action;
         scanf("%d", &action);

         if (room == 1) {
            if (action == 1) {
               livingRoomLightsOn = true;
               printf("Living room lights turned on.\n");
            } else if (action == 2) {
               livingRoomLightsOn = false;
               printf("Living room lights turned off.\n");
            }
         } else if (room == 2) {
            if (action == 1) {
               kitchenLightsOn = true;
               printf("Kitchen lights turned on.\n");
            } else if (action == 2) {
               kitchenLightsOn = false;
               printf("Kitchen lights turned off.\n");
            }
         } else if (room == 3) {
            if (action == 1) {
               bedroomLightsOn = true;
               printf("Bedroom lights turned on.\n");
            } else if (action == 2) {
               bedroomLightsOn = false;
               printf("Bedroom lights turned off.\n");
            }
         }
      }
   } else if (mode == 2) {
      printf("Automatic mode is not yet implemented. Please choose manual mode.\n");
   } else {
      printf("Invalid mode selected.\n");
   }

   return 0;
}